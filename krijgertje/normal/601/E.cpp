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

const int MAXN=5000+10000;
const int MAXQ=30000;
const int MAXW=1000;
const int MAXD=16;
const int P=10000019;
const int Q=1000000007;

int n,wmx,nq;
int v[MAXN],w[MAXN],s[MAXN],t[MAXN];

int mx[MAXD][MAXW+1];
void add(int d,int idx) { for(int i=wmx;i>=w[idx];--i) if(mx[d][i-w[idx]]+v[idx]>mx[d][i]) mx[d][i]=mx[d][i-w[idx]]+v[idx]; }
int calc(int d) { int ret=0; for(int i=wmx;i>=1;--i) ret=((ll)ret*P+mx[d][i])%Q; return ret; }

int qtype[MAXQ],qidx[MAXQ],ret[MAXQ];
void go(int l,int r,int d) {
	//printf("going [%d..%d):",l,r); REPE(i,wmx) printf(" %d",mx[d][i]); puts("");
	if(r-l==1) { if(qtype[l]==3) ret[l]=calc(d); return;	}
	int m=l+(r-l)/2;

	REPE(i,wmx) mx[d+1][i]=mx[d][i];
	FOR(i,m,r) if(qtype[i]==2&&s[qidx[i]]<l) add(d+1,qidx[i]);
	go(l,m,d+1);

	REPE(i,wmx) mx[d+1][i]=mx[d][i];
	FOR(i,l,m) if(qtype[i]==1&&t[qidx[i]]>=r) add(d+1,qidx[i]);
	go(m,r,d+1);
}


void run() {
	scanf("%d%d",&n,&wmx);
	REP(i,n) scanf("%d%d",&v[i],&w[i]),s[i]=-1,t[i]=INT_MAX;
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d",&qtype[i]); if(qtype[i]==1) { scanf("%d%d",&v[n],&w[n]),s[n]=i,t[n]=INT_MAX; qidx[i]=n++; } if(qtype[i]==2) { scanf("%d",&qidx[i]); --qidx[i]; t[qidx[i]]=i; } }
	//REP(i,n) printf("%d: %d..%d v=%d w=%d\n",i,s[i],t[i],v[i],w[i]);

	REPE(i,wmx) mx[0][i]=0;
	REP(i,n) if(s[i]==-1&&t[i]==INT_MAX) add(0,i);
	go(0,nq,0);
	REP(i,nq) if(qtype[i]==3) printf("%d\n",ret[i]);
}


int main() {
	run();
	return 0;
}