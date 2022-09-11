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
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXN=194598;
const int MAXQ=1049658;
const int MAXA=5032107;
const int MAXP=8;
const int MAXCOST=12;
const int MAXS=4*MAXN;

int n,nq;
int a[MAXN];
int ql[MAXQ],qr[MAXQ];

int pmn[MAXA+1];
int b[MAXN]; vector<int> bp[MAXN];

int nxtocc[MAXA+1][MAXP+1];
int nxtcost[MAXN][MAXCOST+1];

void updnxt(int idx,int at,int val,int cost) {
	if(at>=SZ(bp[idx])) {
		int lim=min(MAXP,MAXCOST-cost);
		REPE(othcost,lim) if(nxtocc[val][othcost]!=-1&&(nxtcost[idx][cost+othcost]==-1||nxtocc[val][othcost]<nxtcost[idx][cost+othcost])) nxtcost[idx][cost+othcost]=nxtocc[val][othcost];
		nxtocc[val][cost]=idx;
	} else {
		updnxt(idx,at+1,val,cost);
		updnxt(idx,at+1,val*bp[idx][at],cost-1);
	}
}

struct Seg {
	int cost;
	int sval[MAXS];
	void sinit(int x,int l,int r) {
		if(l==r) {
			sval[x]=nxtcost[l][cost]==-1?INT_MAX:nxtcost[l][cost];
		} else {
			int m=l+(r-l)/2;
			sinit(2*x+1,l,m);
			sinit(2*x+2,m+1,r);
			sval[x]=min(sval[2*x+1],sval[2*x+2]);
		}
	}
	int sget(int x,int l,int r,int L,int R) {
		if(L<=l&&r<=R) {
			return sval[x];
		} else {
			int m=l+(r-l)/2,ret=INT_MAX;
			if(L<=m) ret=min(ret,sget(2*x+1,l,m,L,R));
			if(m+1<=R) ret=min(ret,sget(2*x+2,m+1,r,L,R));
			return ret;
		}
	}
};

Seg seg[MAXCOST+1];

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];

	memset(pmn,-1,sizeof(pmn));
	FORE(i,2,MAXA) if(pmn[i]==-1) for(int j=i;j<=MAXA;j+=i) if(pmn[j]==-1) pmn[j]=i;

	REP(i,n) {
		int x=a[i]; b[i]=1; bp[i].clear();
		while(x!=1) { int p=pmn[x]; assert(x%p==0); x/=p; if(SZ(bp[i])!=0&&bp[i].back()==p) b[i]/=p,bp[i].pop_back(); else b[i]*=p,bp[i].PB(p); }
	}
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
	//printf("b:"); REP(i,n) printf(" %d",b[i]); puts("");
	//printf("bp:"); REP(i,n) { printf(" ("); REPSZ(j,bp[i]) { if(j!=0) printf(","); printf("%d",bp[i][j]); } printf(")"); } puts("");

	memset(nxtocc,-1,sizeof(nxtocc));
	memset(nxtcost,-1,sizeof(nxtcost));
	for(int i=n-1;i>=0;--i) updnxt(i,0,1,SZ(bp[i]));
	REP(i,n) FORE(j,1,MAXCOST) if(nxtcost[i][j-1]!=-1&&(nxtcost[i][j]==-1||nxtcost[i][j-1]<nxtcost[i][j])) nxtcost[i][j]=nxtcost[i][j-1];
	//REP(i,n) REPE(j,MAXCOST) if(nxtcost[i][j]!=-1) printf("%d %d = %d\n",i+1,j,nxtcost[i][j]+1);

	REPE(j,MAXCOST) { seg[j].cost=j; seg[j].sinit(0,0,n-1); }
	REP(i,nq) {
		int l=-1,h=MAXCOST; // (l,h]
		while(l+1<h) {
			int m=l+(h-l)/2;
			int cur=seg[m].sget(0,0,n-1,ql[i],qr[i]);
			if(cur<=qr[i]) h=m; else l=m;
		}
		printf("%d\n",h);
	}
}

int main() {
	run();
	return 0;
}