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

const int MAXLEVEL=62;

int nq;

ll cnt[MAXLEVEL];
ll valshift[MAXLEVEL];
ll nodeshift[MAXLEVEL];

int getlevel(ll x) { int ret=0; while(x!=1) x/=2,++ret; return ret; }

ll ret[MAXLEVEL]; int nret;

void run() {
	cnt[0]=1; FORE(i,1,MAXLEVEL) cnt[i]=cnt[i-1]*2,valshift[i]=nodeshift[i]=0;
	//REP(i,MAXLEVEL) printf("%d: %lld\n",i,cnt[i]);

	scanf("%d",&nq);
	REP(qi,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			ll x,by; scanf("%lld%lld",&x,&by);
			int lev=getlevel(x);
			valshift[lev]=((valshift[lev]+by)%cnt[lev]+cnt[lev])%cnt[lev];
		}
		if(kind==2) {
			ll x,by; scanf("%lld%lld",&x,&by);
			int lev=getlevel(x);
			nodeshift[lev]=((nodeshift[lev]+by)%cnt[lev]+cnt[lev])%cnt[lev];
		}
		if(kind==3) {
			ll x; scanf("%lld",&x);
			int lev=getlevel(x);
			ll pos=cnt[lev]+(x-cnt[lev]+valshift[lev])%cnt[lev];
			nret=0;
			while(true) {
				ret[nret++]=cnt[lev]+(pos-cnt[lev]+cnt[lev]-valshift[lev])%cnt[lev];
				if(pos==1) break;
				pos=(cnt[lev]+(pos-cnt[lev]+nodeshift[lev])%cnt[lev])/2; --lev;
			}
			REP(i,nret) { if(i!=0) printf(" "); printf("%lld",ret[i]); } puts("");
		}
	}
}

int main() {
	run();
	return 0;
}