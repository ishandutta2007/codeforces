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

const int MAXN = 1000000;
const int MOD = 1000000007;

int n;
int p[MAXN];

bool done[MAXN];
vector<int> cyc;

int calc(int a, int b) {
	int ret = 0;
	int x = min(a, b);
	a -= x, b -= x, ret += x;
	assert(a % 3 == 0 && b % 3 == 0);
	ret += 2 * (a / 3);
	ret += 3 * (b / 3);
	return ret;
}

pair<int, int> solve() {
	int ntwo = 0; while ((n - 2 * ntwo) % 3 != 0) ++ntwo;
	int nthree = (n - 2 * ntwo) / 3;
	int days = 1;
	REP(i, nthree) days = (ll)days * 3 % MOD;
	REP(i, ntwo) days = (ll)days * 2 % MOD;
	
	cyc.clear();
	REP(i, n) done[i] = false;
	REP(i, n) if (!done[i]) {
		int len = 0, at = i;
		while (!done[at]) {
			done[at] = true;
			++len;
			at = p[at];
		}
		cyc.PB(len);
	}
	//printf("cyc:"); REPSZ(i, cyc) printf(" %d", cyc[i]); puts("");
	//printf("ntwo=%d nthree=%d\n", ntwo, nthree);

	int best = INT_MAX;
	REP(rep, 2) {
		if (rep == 1 && ntwo != 2) continue;
		int special = 2, remspecial = ntwo;
		if (rep == 1) special = 4, remspecial = 1;
		int cur = 0;
		vector<int> lst = cyc;
		vector<int> nlst;
		//printf("A cur=%d special=%d remspecial=%d lst:", cur, special, remspecial); REPSZ(i, lst) printf(" %d", lst[i]); puts("");
		{
			REPSZ(i, lst) {
				int len = lst[i];
				if (len >= remspecial * special) {
					int times = (len - remspecial * special) / 3;
					len -= 3 * times;
					cur += times - (len == 0 ? 1 : 0);
				}
				if (len != 0) nlst.PB(len);
			}
			lst = nlst;
			nlst.clear();
		}
		{
			vector<int> rem(remspecial * special + 3, 0);
			REPSZ(i, lst) {
				int len = lst[i];
				assert(len < SZ(rem));
				++rem[len];
			}
			if (remspecial == 0) {
				best = min(best, cur + calc(rem[1], rem[2]));
			} else if (remspecial == 1) {
				FORSZ(a, -1, rem) FORSZ(b, a, rem) FORSZ(c, b, rem) FORSZ(d, c, rem) {
					vector<int> zrem = rem; bool ok = true; int zcnt = 0, zsum = 0;
					if (a != -1) if (zrem[a] == 0) ok = false; else --zrem[a], ++zcnt, zsum += a;
					if (b != -1) if (zrem[b] == 0) ok = false; else --zrem[b], ++zcnt, zsum += b;
					if (c != -1) if (zrem[c] == 0) ok = false; else --zrem[c], ++zcnt, zsum += c;
					if (d != -1) if (zrem[d] == 0) ok = false; else --zrem[d], ++zcnt, zsum += d;
					if (!ok || zsum < special) continue;
					int now = cur + zcnt - 1;
					{
						zsum -= special;
						if (zsum != 0) ++now;
					}
					if (zsum != 0) {
						int times = zsum / 3;
						zsum -= 3 * times;
						now += times - (zsum == 0 ? 1 : 0);
						if (zsum != 0) ++zrem[zsum];
					}
					//printf("[%d,%d,%d,%d]: zsum=%d zcnt=%d zrem=", a, b, c, d, zsum, zcnt); REPSZ(i, zrem) printf(" %d", zrem[i]); puts("");
					FORSZ(i, 3, rem) {
						int times = i / 3;
						int ni = i - 3 * times;
						if (ni != 0) zrem[ni] += zrem[i];
						now += zrem[i] * (times - (ni == 0 ? 1 : 0));
						zrem[i] = 0;
					}
					now += calc(zrem[1], zrem[2]);
					//printf("->%d\n", now);
					best = min(best, now);
				}
			} else if (remspecial == 2) {
				FORSZ(a, -1, rem) FORSZ(b, a, rem) FORSZ(c, -1, rem) FORSZ(d, c, rem) {
					vector<int> zrem = rem; bool ok = true; int zcnt1 = 0, zsum1 = 0, zcnt2 = 0, zsum2 = 0;
					if (a != -1) if (zrem[a] == 0) ok = false; else --zrem[a], ++zcnt1, zsum1 += a;
					if (b != -1) if (zrem[b] == 0) ok = false; else --zrem[b], ++zcnt1, zsum1 += b;
					if (c != -1) if (zrem[c] == 0) ok = false; else --zrem[c], ++zcnt2, zsum2 += c;
					if (d != -1) if (zrem[d] == 0) ok = false; else --zrem[d], ++zcnt2, zsum2 += d;
					if (!ok || zsum1 < special || zsum2 < special) continue;
					int now = cur + zcnt1 - 1 + zcnt2 - 1;
					{
						zsum1 -= special;
						if (zsum1 != 0) ++now;
					}
					if (zsum1 != 0) {
						int times = zsum1 / 3;
						zsum1 -= 3 * times;
						now += times - (zsum1 == 0 ? 1 : 0);
						if (zsum1 != 0) ++zrem[zsum1];
					}
					{
						zsum2 -= special;
						if (zsum2 != 0) ++now;
					}
					if (zsum2 != 0) {
						int times = zsum2 / 3;
						zsum2 -= 3 * times;
						now += times - (zsum2 == 0 ? 1 : 0);
						if (zsum2 != 0) ++zrem[zsum2];
					}
					//printf("[%d,%d,%d,%d]: zsum=%d zcnt=%d zrem=", a, b, c, d, zsum, zcnt); REPSZ(i, zrem) printf(" %d", zrem[i]); puts("");
					FORSZ(i, 3, rem) {
						int times = i / 3;
						int ni = i - 3 * times;
						if (ni != 0) zrem[ni] += zrem[i];
						now += zrem[i] * (times - (ni == 0 ? 1 : 0));
						zrem[i] = 0;
					}
					now += calc(zrem[1], zrem[2]);
					//printf("->%d\n", now);
					best = min(best, now);
				}
			} else {
				assert(false);
			}
		}
	}
	return MP(days, best);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &p[i]), --p[i];
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}