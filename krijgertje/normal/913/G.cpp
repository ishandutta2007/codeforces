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

const int MAXALEN=11;
const int MAXBLEN=11+5;

char sa[MAXALEN+1]; int salen;
char sb[MAXBLEN+1]; int sblen;

ll mlt(ll a,ll b,ll mod) {
	//  a*b%mod;
	//ll ret=0; while(true) { if(b&1) ret=(ret+a)%mod; if((b>>=1)==0) return ret; a=(a+a)%mod; }
	ll chk=((a*b-(ll)((long double)a*b/mod)*mod)%mod+mod)%mod;
	//assert(ret==chk);
	return chk;
} 
ll pw(ll x,ll n,ll mod) { ll ret=1; while(true) { if(n&1) ret=mlt(ret,x,mod); if((n>>=1)==0) return ret; x=mlt(x,x,mod); } }

ll solve() {
	for(sblen=salen;;++sblen) {
		ll mod2=1LL<<sblen,cur=0;
		REP(i,salen) {
			sb[i]=sa[i];
			cur=(cur*10+sa[i]-'0')%mod2;
		}
		REP(i,sblen-salen) cur=cur*10%mod2;
		cur=(mod2-cur)%mod2;
		bool ok=false;
		for(int j=0;;++j) {
			ll left=cur+j*mod2;
			REP(i,sblen-salen) sb[sblen-i-1]='0'+left%10,left/=10;
			sb[sblen]='\0';
			if(left!=0) break;
			if(sb[sblen-1]!='0'&&sb[sblen-1]!='5') { ok=true; break; }
		}
		if(ok) break;
	}
	//printf("%s -> %s\n",sa,sb);

	// 2^x=want mod 5^k / 2^y=1 mod 5^k
	ll want=0; REP(i,sblen) want=10*want+sb[i]-'0';
	int k=1; ll cmod=5; ll x=1; while(pw(2,x,cmod)!=want%cmod) ++x; ll y=1; while(pw(2,y,cmod)!=1) ++y;
	while(true) {
		//printf("k=%d cmod=%lld x=%lld y=%lld\n",k,cmod,x,y);
		ll nmod=cmod*5,nx=x,ny=y; while(pw(2,nx,nmod)!=want%nmod) nx+=y; while(pw(2,ny,nmod)!=1) ny+=y;
		if(k==sblen) break;
		++k; cmod=nmod; x=nx; y=ny;
	}
	ll ret=x; while(ret<sblen) ret+=y;
	//fprintf(stderr,"%lld vs %lld\n",want%cmod,pw(2,x,cmod));
	return ret;
}

void run() {
	scanf("%s",sa); salen=strlen(sa);
	printf("%lld\n",solve());
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}