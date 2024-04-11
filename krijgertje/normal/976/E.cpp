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

const int MAXN=200000;
struct C { int hp,dmg; };
bool operator<(const C &a,const C &b) { return a.hp-a.dmg>b.hp-b.dmg; }

int n,na,nb;
C c[MAXN];

ll calc(int aidx) {
	int rem=nb; if(aidx!=-1) --rem;
	ll ret=0;
	REP(i,n) {
		if(i==aidx) {
			ret+=((ll)c[i].hp)<<na;
		} else if(rem>0&&c[i].hp>c[i].dmg) {
			ret+=c[i].hp; --rem;
		} else {
			ret+=c[i].dmg;
		}
	}
	return ret;
}


void run() {
	scanf("%d%d%d",&n,&na,&nb);
	REP(i,n) scanf("%d%d",&c[i].hp,&c[i].dmg);

	sort(c,c+n);
	ll ret=calc(-1);

	int numgain=0; REP(i,n) if(c[i].hp>c[i].dmg) ++numgain;
	int numchange=min(nb,numgain);

	if(numchange>0&&nb>0) {
		pair<ll,int> best=MP(0,-1);
		REP(i,numchange) {
			ll nhp=((ll)c[i].hp)<<na;
			ll gain=nhp-c[i].hp; if(gain>best.first) best=MP(gain,i);
		}
		if(best.second!=-1) ret=max(ret,calc(best.second));
	}
	if(numchange<n&&nb>0) {
		pair<ll,int> best=MP(0,-1);
		FOR(i,numchange,n) {
			ll nhp=((ll)c[i].hp)<<na;
			ll gain=nhp-c[i].dmg; if(gain>best.first) best=MP(gain,i);
		}
		if(best.second!=-1) ret=max(ret,calc(best.second));
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}