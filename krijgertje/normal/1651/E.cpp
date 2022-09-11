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
#include <chrono>
#include <random>
#include <functional>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 1500;

int n;
vector<int> adj[2 * MAXN];

ll solve() {
	vector<bool> done(2 * n, false);
	ll ret = 0;
	REP(i, 2 * n) if (!done[i]) {
		vector<int> cyc;
		int at = i;
		while (!done[at]) {
			done[at] = true;
			cyc.PB(at);
			at = SZ(cyc) == 1 ? adj[at][0] : adj[at][0] ^ adj[at][1] ^ cyc[SZ(cyc) - 2];
		}
		//printf("cyc:"); for (int x : cyc) printf(" %d", x + 1); puts("");
		{
			int lmn = INT_MAX, lmx = INT_MIN, rmn = INT_MAX, rmx = INT_MIN;
			for (int x : cyc) if (x < n) lmn = min(lmn, x), lmx = max(lmx, x); else rmn = min(rmn, x - n), rmx = max(rmx, x - n);
			ll ways = (ll)(lmn + 1) * (n - lmx) * (rmn + 1) * (n - rmx);
			int matched = SZ(cyc) / 2;
			ret += ways * matched;
		}
		REPSZ(j, cyc) {
			int lmn = INT_MAX, lmx = INT_MIN, rmn = INT_MAX, rmx = INT_MIN;
			int y = cyc[SZ(cyc) - 1];
			REPSZ(k, cyc) {
				int x = cyc[k];
				if (x < n) lmn = min(lmn, x), lmx = max(lmx, x); else rmn = min(rmn, x - n), rmx = max(rmx, x - n);
				if (y < n && lmn <= y && y <= lmx || y >= n && rmn <= y - n && y - n <= rmx) break;
				int z = cyc[k + 1];
				if (!(z < n && lmn <= z && z <= lmx || z >= n && rmn <= z - n && z - n <= rmx)) {
					int a = lmn + 1, b = n - lmx, c = rmn + 1, d = n - rmx;
					if (y < n && y < lmn) a = min(a, lmn - y);
					if (y < n && y > lmx) b = min(b, y - lmx);
					if (y >= n && y - n < rmn) c = min(c, rmn - (y - n));
					if (y >= n && y - n > rmx) d = min(d, (y - n) - rmx);
					if (z < n && z < lmn) a = min(a, lmn - z);
					if (z < n && z > lmx) b = min(b, z - lmx);
					if (z >= n && z - n < rmn) c = min(c, rmn - (z - n));
					if (z >= n && z - n > rmx) d = min(d, (z - n) - rmx);
					ll ways = (ll)a * b * c * d;
					int matched = (k + 1) / 2;
					ret += ways * matched;
				}
			}
			rotate(cyc.begin(), cyc.begin() + 1, cyc.end());
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}