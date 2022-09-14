#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;

int preflen[3]={6,7,8},pref[3][7][5]={{{1,4,1,0,1},{3,4,5,1,2},{0,3,1,4,5},{0,2,2,-1,-1},{2,5,1,-1,-1}},{{2,4,1,1,2},{3,4,8,4,5},{0,3,4,4,6},{0,5,1,5,6},{0,1,2,-1,-1},{1,6,1,-1,-1}},{{0,4,1,3,4},{0,2,6,4,5},{2,5,2,4,6},{1,2,3,4,7},{1,6,1,5,6},{1,3,2,5,7},{3,7,1,6,7}}};
int sufflen[5]={2,3,6,7,8},suff[5][7][5]={{{0,1,1,-1,-1}},{{0,2,1,-1,-1},{1,2,1,-1,-1}},{{0,5,1,0,1},{3,5,1,3,4},{1,4,1,4,5},{1,2,7,-1,-1},{2,5,3,-1,-1}},{{0,4,1,0,1},{1,6,1,0,2},{2,5,1,1,2},{3,4,1,2,3},{4,6,2,-1,-1},{5,6,3,-1,-1}},{{0,4,1,0,1},{1,5,1,0,2},{2,7,2,0,3},{3,6,1,1,2},{4,5,2,1,3},{5,7,3,2,3},{6,7,6,3,4}}};
int midlen[2]={7,8},mid[2][7][5]={{{0,5,1,0,1},{1,4,1,0,2},{2,3,1,1,2},{4,5,2,5,6},{3,4,3,-1,-1},{3,6,1,-1,-1}},{{0,5,1,0,1},{1,4,1,0,2},{4,5,2,1,2},{3,4,4,5,6},{3,6,1,5,7},{2,3,2,6,7},{2,7,1,-1,-1}}};
int fullen[2]={5,6},full[2][7][5]={{{0,4,1,0,1},{1,3,1,3,4},{1,2,4,-1,-1},{2,4,2,-1,-1}},{{0,5,1,0,1},{3,5,1,3,4},{1,4,1,4,5},{1,2,6,-1,-1},{2,5,2,-1,-1}}};

int n,m,npair;
int u[100001],v[100001],c[100001];
int x[100001],y[100001];


void print(int len,int part[7][5]) {
	bool first=n==0;
	REP(i,len-1) { u[m]=n+part[i][0]+(first?1:0); v[m]=n+part[i][1]+(first?1:0); c[m]=part[i][2]; ++m; }
	REP(i,len-1) if(part[i][3]!=-1&&part[i][4]!=-1) { x[npair]=n+part[i][3]+(first?1:0); y[npair]=n+part[i][4]+(first?1:0); ++npair; }
	n+=first?len:len-1;
}

void create(int q) {
	n=0,m=0,npair=0;
	REP(i,2) if(fullen[i]==q) { print(fullen[i],full[i]); return; }
	for(int i=2;i>=0;--i) REP(j,5) REP(k,2) {
		int rem=q-preflen[i]-(sufflen[j]-1); if(rem<0) continue;
		if(rem%(midlen[k]-1)==0) {
			int nmid=rem/(midlen[k]-1);
//			printf("pref=%d, %d*mid=%d, suff=%d\n",i,nmid,k,j);
			print(preflen[i],pref[i]);
			REP(x,nmid) print(midlen[k],mid[k]);
			print(sufflen[j],suff[j]);
			return;
		}
	}
	assert(false);
}

int t[100001];
int mark[100001],curmark;
int d[100001],q[100001],qh,qt;
int first[100001],nxt[200002];

void check() {
	memset(first,-1,sizeof(first));
	REP(i,m) { nxt[2*i+0]=first[u[i]]; first[u[i]]=2*i+0; nxt[2*i+1]=first[v[i]]; first[v[i]]=2*i+1; }

	memset(t,0,sizeof(t)); memset(mark,-1,sizeof(mark)); curmark=-1;
	REP(i,m) FORE(j,u[i],v[i]) t[j]+=c[i];
	bool ok=true;
	REP(i,n/2) {
		int expect=0; FORE(z,x[i],y[i]) expect+=t[z];
		qh=qt=0; ++curmark; mark[x[i]]=curmark; d[x[i]]=0; q[qh++]=x[i];
		while(qt<qh) {
			int at=q[qt++];
			//printf("%d: %d\n",i,at);
			if(at==y[i]) break;
			for(int z=first[at];z!=-1;z=nxt[z]) {
				int e=z/2,side=z%2,to=side==0?v[e]:u[e];
				if(mark[to]==curmark) continue;
				mark[to]=curmark; d[to]=d[at]+c[e]; q[qh++]=to;
			}
		}
		int have=d[y[i]];
//		printf("%d vs %d\n",expect,have);
		if(expect!=have) ok=false;
	}
	assert(ok);
}

void run() {
	int q; scanf("%d",&q);
	create(q);
	assert(n==q); assert(m==q-1); assert(npair>=q/2);
//	check();
	REP(i,m) printf("%d %d %d\n",u[i],v[i],c[i]);
	REP(i,n/2) printf("%d %d\n",x[i],y[i]);
}

int main() {
	run();
	return 0;
}