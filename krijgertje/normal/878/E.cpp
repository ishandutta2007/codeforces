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

const int MAXN=100000;
const int MAXLG=16;
const int MOD=1000000007;
const int INV2=(MOD+1)/2;
const int MINVAL=-1000000000;
const int MAXQ=100000;

int n,nq;
int a[MAXN];
int ql[MAXQ],qr[MAXQ];

int steps[MAXN]; ll val[MAXN]; // if from i we take steps[i] items, we get val[i] and at least one of the following is true val[i]<=0 OR val[i]+MINVAL>=0 OR steps[i]=i+1

int p2[MAXN+1],ip2[MAXN+1];
int psum[MAXN+1];

int up[MAXN+1][MAXLG+1];
ll upsum[MAXN+1][MAXLG+1];

int ans[MAXQ];

void solve() {
	REP(i,n) {
		steps[i]=1; val[i]=a[i];
		while(val[i]>0&&val[i]+MINVAL<0&&steps[i]!=i+1) val[i]=a[i-steps[i]]+2*val[i],++steps[i];
		//printf("%d: steps=%d val=%lld\n",i,steps[i],val[i]);
	}

	p2[0]=ip2[0]=1; FORE(i,1,n) p2[i]=(ll)p2[i-1]*2%MOD,ip2[i]=(ll)ip2[i-1]*INV2%MOD;
	psum[0]=0; REP(i,n) psum[i+1]=(psum[i]+(ll)p2[i]*a[i]%MOD+MOD)%MOD;

	REP(i,n) up[i+1][0]=val[i]<=0?i+1-steps[i]:0,upsum[i+1][0]=val[i]<=0?val[i]:0;
	FORE(k,1,MAXLG) REPE(i,n) up[i][k]=up[up[i][k-1]][k-1],upsum[i][k]=upsum[i][k-1]+upsum[up[i][k-1]][k-1];

	REP(qi,nq) {
		int l=ql[qi],r=qr[qi]; --l;
		ll sum=0;
		for(int k=MAXLG;k>=0;--k) if(up[r][k]>l) sum+=upsum[r][k],r=up[r][k];
		--r;
		int first=(ll)(psum[r+1]+MOD-psum[l])*ip2[l]%MOD;
		ans[qi]=((first+2*sum)%MOD+MOD)%MOD;
		//printf("->[%d..%d]=%d: +2*%lld = %d (%d)\n",l,r,first,sum,ans[qi],up[r+2][1]);
	}
}


void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&a[i]); REP(i,nq) scanf("%d%d",&ql[i],&qr[i]);
	solve();
	REP(qi,nq) printf("%d\n",ans[qi]);
}

ll bf(vector<ll> x) {
	if(SZ(x)==1) return x[0];
	ll ret=LLONG_MIN;
	FORSZ(i,1,x) {
		vector<ll> y(SZ(x)-1);
		REP(j,i-1) y[j]=x[j]; y[i-1]=x[i-1]+2*x[i]; FORSZ(j,i+1,x) y[j-1]=x[j];
		ll cur=bf(y); if(cur>ret) ret=cur;
	}
	//printf("bf"); REPSZ(i,x) printf(" %lld",x[i]); printf(" -> %lld\n",ret);
	return ret;
}

void stress() {
	REP(rep,10000) {
		// rand()%2000*1000000+rand()%1000*1000+rand()%1001-1000000000
		n=9; nq=1; REP(i,n) a[i]=rand()%2000*1000000+rand()%1000*1000+rand()%1001-1000000000; ql[0]=rand()%n+1,qr[0]=rand()%n+1; if(ql[0]>qr[0]) swap(ql[0],qr[0]);
		solve();
		vector<ll> x(qr[0]-ql[0]+1); REPSZ(i,x) x[i]=a[ql[0]-1+i];
		int chk=(bf(x)%MOD+MOD)%MOD;
		if(ans[0]!=chk) {
			printf("%d vs %d\n",ans[0],chk);
			printf("%d %d\n",n,nq); REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts(""); REP(i,nq) printf("%d %d\n",ql[i],qr[i]); break;
		} else printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}