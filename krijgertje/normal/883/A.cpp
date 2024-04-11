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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXGUEST = 100000;

int nemp, nguest, a; ll dopen;
ll tguest[MAXGUEST];

ll solve() {
	ll ret = 0;
	ll t = 1; int at = 0;
	while (at < nguest || t <= (ll)nemp*a) {
		ll tg = at < nguest ? tguest[at] : LLONG_MAX;
		ll te = t <= (ll)nemp*a ? (t + a - 1) / a * a : LLONG_MAX;
		ll topen = min(tg, te); assert(topen != LLONG_MAX);
		ll tclose = topen + dopen;
		//printf("%lld: tg=%lld te=%lld topen=%lld tclose=%lld\n", t, tg, te, topen, tclose);
		++ret;
		t = tclose + 1;
		while (at < nguest && tguest[at] < t) ++at;
		if (topen == te) {
			ll nte = tclose + 1 <= (ll)nemp*a ? (tclose + 1 + a - 1) / a * a : LLONG_MAX;
			if (nte != LLONG_MAX) {
				ll dt = nte - te;
				// te+times*dt<=(ll)nemp*a -> times<=((ll)nemp*a-te)/dt
				// te+times*dt<=tguest[at] -> times<=(tguest[at]-te)/dt
				ll times = min(((ll)nemp*a - te) / dt, at < nguest ? (tguest[at] - te) / dt : LLONG_MAX);
				//printf("\tnte=%lld dt=%lld times=%lld\n", nte, dt, times);
				ret += times;  t += times*dt;
				while (at < nguest && tguest[at] < t) ++at;
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d%lld", &nemp, &nguest, &a, &dopen);
	REP(i, nguest) scanf("%lld", &tguest[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	//stress();
	return 0;
}