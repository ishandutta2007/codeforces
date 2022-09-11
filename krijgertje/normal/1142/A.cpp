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
#include <bitset>
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

int n,k;
int sdst,tdst;

ll calcsteps(ll a,ll b,ll step,ll mod) {
	ll at=a,ret=0;
	do {
		at+=step,++ret; if(at>=mod) at-=mod;
	} while(at!=b);
	return ret;
}

pair<ll,ll> solve() {
	pair<ll,ll> ret=MP(LLONG_MAX,LLONG_MIN);

	REP(sdir,2) REP(tdir,2) {
		int s=sdir==0?sdst:(k-sdst)%k,t=tdir==0?tdst:(k-tdst)%k,smallstep=(t-s+k)%k;
		ll periodlen=calcsteps(s,s,smallstep,k);
		assert((ll)periodlen*smallstep%k==0);
		int bigdelta=(ll)periodlen*smallstep/k;
		// (bigstep+periodlen*i)*x=0 mod n
		int g=gcd(periodlen,n);
		//printf("s=%d t=%d smallstep=%d -> periodlen=%lld g=%d\n",s+1,t+1,smallstep,periodlen,g);

		REP(i,n/g) {
			int bigstep=(bigdelta+(ll)periodlen*i)%n;
			int gg=gcd(bigstep,n);
			ll cur=(ll)periodlen*(n/gg);
			// bigstep*x=0 mod n
			//ll cur=periodlen*calcsteps(0,0,bigstep,n);
			//assert(cur==chk);
			assert(cur%periodlen==0);
			ret.first=min(ret.first,cur);
			ret.second=max(ret.second,cur);
			//printf("\t%d: %lld [%d]\n",i,cur,bigstep);
		}




	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&k);
	scanf("%d%d",&sdst,&tdst);
	pair<ll,ll> ans=solve();
	printf("%lld %lld\n",ans.first,ans.second);
}

void stress() {
	REP(rep,100) {
		n=rand()%100+1,k=rand()%100+1,sdst=rand()%k,tdst=rand()%k;
		solve();
	}
}

int main() {
	run();
	//stress();
	return 0;
}