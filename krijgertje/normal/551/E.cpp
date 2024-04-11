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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXBLOCK=70;
const int MAXN=500000;
const int MAXQ=50000;
const int BLOCKSZ=(MAXQ+MAXBLOCK-1)/MAXBLOCK;

int n,nq;
int a[MAXN];
int qtype[BLOCKSZ],ql[BLOCKSZ],qr[BLOCKSZ],qx[BLOCKSZ],bcnt;

int x[2*BLOCKSZ+2],nx;
int y[2*BLOCKSZ+2];
pair<int,int> b[MAXN];

void inc(int &a,int by) { if(a>INT_MAX-by) a=INT_MAX; else a+=by; }
void dec(int &a,int by) { if(a<by) a=0; else a-=by; }
void process() {
	//printf("processing\n"); REP(i,bcnt) printf("%d: %d %d %d %d\n",i,qtype[i],ql[i],qr[i],qx[i]);
	nx=0; x[nx++]=0; x[nx++]=n; REP(i,bcnt) if(qtype[i]==1) x[nx++]=ql[i],x[nx++]=qr[i];
	sort(x,x+nx); nx=unique(x,x+nx)-x;

	REP(i,n) b[i]=MP(a[i],i);
	REP(i,nx-1) sort(b+x[i],b+x[i+1]),y[i]=0;
	
	REP(i,bcnt) {
		if(qtype[i]==1) {
			REP(j,nx-1) if(ql[i]<=x[j]&&x[j+1]<=qr[i]) inc(y[j],qx[i]);
		}
		if(qtype[i]==2) {
			int li=INT_MAX,hi=INT_MIN;
			//printf("searching %d: ",qx[i]); REP(j,nx-1) printf("(%d in %d..%d)",qx[i]-y[j],x[j],x[j+1]); puts("");
			REP(j,nx-1) {
				int want=qx[i]; dec(want,y[j]); if(want==0) continue;
				int l=x[j]-1,h=x[j+1];
				while(l+1<h) { int m=l+(h-l)/2; if(b[m].first<want) l=m; else h=m; }
				if(h==x[j+1]||b[h].first!=want) continue;
				li=b[h].second; break;
			}
			if(li==INT_MAX) { printf("-1\n"); continue; }
			for(int j=nx-2;j>=0;--j) {
				int want=qx[i]; dec(want,y[j]); if(want==0) continue;
				int l=x[j]-1,h=x[j+1];
				while(l+1<h) { int m=l+(h-l)/2; if(b[m].first>want) h=m; else l=m; }
				if(l==x[j]-1||b[l].first!=want) continue;
				hi=b[l].second; break;
			}
			printf("%d\n",hi-li);
		}
	}
	REP(i,nx-1) FOR(j,x[i],x[i+1]) inc(a[j],y[i]);
	bcnt=0;
}



void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);

	bcnt=0;
	REP(qi,nq) {
		scanf("%d",&qtype[bcnt]);
		if(qtype[bcnt]==1) scanf("%d%d%d",&ql[bcnt],&qr[bcnt],&qx[bcnt]),--ql[bcnt];
		if(qtype[bcnt]==2) scanf("%d",&qx[bcnt]);
		if(++bcnt==BLOCKSZ||qi==nq-1) process();
	}
}

int main() {
	run();
	return 0;
}