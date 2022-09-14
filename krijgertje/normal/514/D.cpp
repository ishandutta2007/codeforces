#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n,ntype,have;

int val[100000][5];

int tval[1<<18][5];
void init(int x,int l,int r) {
	if(l==r) {
		REP(j,ntype) tval[x][j]=val[l][j];
	} else {
		int m=l+(r-l)/2;
		init(2*x+1,l,m); init(2*x+2,m+1,r);
		REP(j,ntype) tval[x][j]=max(tval[2*x+1][j],tval[2*x+2][j]);
	}
	//printf("inited %d..%d:",l,r); REP(j,ntype) printf(" %d",tval[x][j]); puts("");
}
int get(int x,int l,int r,int L,int R,int j) {
	if(L<=l&&r<=R) return tval[x][j];
	int m=l+(r-l)/2;
	if(R<=m) return get(2*x+1,l,m,L,R,j);
	if(m+1<=L) return get(2*x+2,m+1,r,L,R,j);
	return max(get(2*x+1,l,m,L,R,j),get(2*x+2,m+1,r,L,R,j));
}

int retneed[5];

void run() {
	scanf("%d%d%d",&n,&ntype,&have);
	REP(i,n) REP(j,ntype) scanf("%d",&val[i][j]);
	//REP(i,n) { REP(j,ntype) printf("%d ",val[i][j]); puts(""); }

	init(0,0,n-1);
	int ret=0; REP(j,ntype) retneed[j]=0;
	REP(i,n) {
		int l=i-1,h=n;
		while(l+1<h) {
			int m=l+(h-l)/2;
			int need=0;
			REP(j,ntype) {
				int now=get(0,0,n-1,i,m,j);
				//printf("%d..%d (%d) -> %d\n",i,m,j,now);
				need+=now;
			}
			if(need<=have) l=m; else h=m;
		}
		//printf("%d..%d\n",i,l);
		int cur=l-i+1;
		if(cur>ret) { ret=cur; REP(j,ntype) retneed[j]=get(0,0,n-1,i,l,j); }
	}
	REP(j,ntype) { if(j!=0) printf(" "); printf("%d",retneed[j]); } puts("");
}

int main() {
	run();
	return 0;
}