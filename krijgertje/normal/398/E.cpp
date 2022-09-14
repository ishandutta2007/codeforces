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

const int MOD=1000000007;
ll fac[13];

int n,nunknown;
int a[100000];
int r[100000];
bool done[100000];

int todo[12],ntodo;
int sumtodo[1<<12],cnttodo[1<<12];
int cnt[100001];

bool twoswaps;
ll cur;
int nval;
int atval[100001];
int nxtval[1000000];
int prvval[1000000];
ll val[1000000];
ll invval[1000000];


ll mypow(ll x,ll n) { if(n==0) return 1; if(n%2==1) return x*mypow(x,n-1)%MOD; return mypow(x*x%MOD,n/2); }
ll inverse(ll a) { return mypow(a,MOD-2); }
ll calcnext(int n,int k,ll pval,ll ppval) {
	return (ppval*(k-1)%MOD+pval)*n%MOD;
}

ll calc() {
	ll ret=twoswaps?cur:1;
/*	int maxcnt=-1;
	ll check=1;
	FORE(i,1,n) if(cnt[i]>0) {
		maxcnt=i;
		ll a=1,b=i;
		FORE(j,2,cnt[i]) {
			ll c=i*(a*(j-1)%MOD+b)%MOD;
			assert(c==calcnext(i,j,b,a));
			a=b,b=c;
		}
		check=check*b%MOD;
	}
	if(maxcnt<=2) check=1;
	if(ret!=check) {
		FORE(i,1,n) if(cnt[i]>0) printf("%d*%d (%lld) ",cnt[i],i,val[i]); puts("");
		printf("%lld vs %lld\n",ret,check);
	} */
	return ret;
}

ll go(int left,int depth) {
	if(left==0) return calc();
	ll ret=0;
	for(int nleft=0;nleft<left-nleft;nleft=(nleft+(1<<ntodo)-left)&left) {
		//REP(i,depth) printf("  "); printf("%x -> %x\n",left,nleft);
		int now=left-nleft,i=sumtodo[now],j=cnt[i]+1;

		++cnt[i];
		int at=atval[i];
		ll pcur=cur;
		cur=cur*invval[at]%MOD;
		if(nxtval[at]==-1) { 
			ll nxt=j==1?i:calcnext(i,j,val[at],val[prvval[at]]);
			{ val[nval]=nxt; invval[nval]=inverse(nxt); nxtval[nval]=-1; prvval[nval]=at; nxtval[at]=nval; ++nval; }
		}
		cur=cur*val[nxtval[at]]%MOD;
		atval[i]=nxtval[at];
		bool ptwoswaps=twoswaps; if(i>2) twoswaps=true;
		ll sub=go(nleft,depth+1);
		twoswaps=ptwoswaps;
		atval[i]=at;
		cur=pcur;
		--cnt[i];
		ret+=fac[cnttodo[now]-1]*sub%MOD;
	}
	return ret%MOD;
}

void run() {
	scanf("%d%d",&n,&nunknown);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) --a[i];
	memset(r,-1,sizeof(r)); REP(i,n) if(a[i]!=-1) r[a[i]]=i;

	memset(done,false,sizeof(done));
	memset(cnt,0,sizeof(cnt));
	ntodo=0;
	REP(i,n) if(a[i]==-1) {
		int ccnt=0;
		for(int at=i;at!=-1;at=r[at]) { done[at]=true; ++ccnt; }
		todo[ntodo++]=ccnt;
	}
	REP(i,n) if(!done[i]) {
		int ccnt=0;
		for(int at=i;!done[at];at=r[at]) { done[at]=true; ++ccnt; }
		cnt[ccnt]++;
	}

//	REP(i,ntodo) printf("todo: %d\n",todo[i]);
//	REPE(i,n) if(cnt[i]>0) printf("%d (%d times)\n",i,cnt[i]);

	sumtodo[0]=0; REP(i,ntodo) REP(j,1<<i) sumtodo[j|(1<<i)]=sumtodo[j]+todo[i];
	cnttodo[0]=0; REP(i,ntodo) REP(j,1<<i) cnttodo[j|(1<<i)]=cnttodo[j]+1;
	//REP(i,1<<ntodo) printf("%d: %d\n",i,sumtodo[i]);

	cur=1; twoswaps=false; nval=0; memset(atval,-1,sizeof(atval));
	FORE(i,1,n) {
		if(cnt[i]>0&&i>2) twoswaps=true;
		{ val[nval]=1; invval[nval]=1; nxtval[nval]=prvval[nval]=-1; atval[i]=nval; ++nval; }
		FORE(j,1,cnt[i]) {
			int at=atval[i];
			ll nxt=j==1?i:calcnext(i,j,val[at],val[prvval[at]]);
			{ val[nval]=nxt; invval[nval]=inverse(nxt); nxtval[nval]=-1; prvval[nval]=at; nxtval[at]=nval; atval[i]=nval; ++nval; }
		}
		cur=cur*val[atval[i]]%MOD;
	}

	ll ret=go((1<<ntodo)-1,0);
	cout<<ret<<endl;
}

int main() {
	fac[0]=1; FORE(i,1,12) fac[i]=fac[i-1]*i;
	run();
	return 0;
}