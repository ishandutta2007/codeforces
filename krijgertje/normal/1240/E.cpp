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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 500000;
const int MAXLEN = 500000;

int n;
int a[MAXN];

int cnt[MAXLEN + 1]; // cnt[k] = # logs that have size == k
int sum[MAXLEN + 1]; // sum[k] = # logs that have size >= k
int prv[MAXLEN + 1]; // prv[k] = last log <= k that has cnt > 0 or -1 if it doesn't exist

ll solve() {
	int mxlen = 0; REP(i, n) mxlen = max(mxlen, a[i]);
	REPE(i, mxlen) cnt[i] = 0;
	REP(i, n) ++cnt[a[i]];
	sum[mxlen] = cnt[mxlen]; for (int i = mxlen - 1; i >= 0; --i) sum[i] = sum[i + 1] + cnt[i];
	REPE(i, mxlen) prv[i] = cnt[i] > 0 ? i : i - 1 >= 0 ? prv[i - 1] : -1;
	ll ret = 0;
	for (int y = 2; y <= mxlen; ++y) {
		ll have = 0;
		for (int k = y; k <= mxlen; k += y) have += sum[k];
		//printf("%d: %lld\n", y, have);

		// take both x-es from one log
		{
			int mxtake = mxlen / y;
			int lim = mxlen + 1;
			int best = -1;
			for (int take = mxtake; take >= 0; --take) {
				int nlim = take * y;
				int cur = prv[lim - 1];
				if (cur != -1 && cur >= nlim) {
					int rem = cur - nlim;
					if (best == -1 || rem > best) best = rem;
				}
				if (best != -1) {
					ll x = min(have - take, ((ll)take * y + best) / 2);
					if (x >= 2) ret = max(ret, x * y);
					//printf("\tAtake %d -> %lld -> %lld\n", take, x, x * y);
				}
				lim = nlim;
			}
		}

		// take the x-es from different logs
		{
			int mxtake = 2 * (mxlen / y);
			int lim = mxlen + 1;
			int best1 = -1, best2 = -1;
			for (int take = mxtake; take >= 0; --take) {
				if (take % 2 == 0) {
					int nlim = (take / 2) * y;
					int cur = prv[lim - 1];
					if (cur != -1 && cur >= nlim) {
						int rem = cur - nlim;
						if (best1 == -1 || rem > best1) best2 = best1, best1 = rem; else if (best2 == -1 || rem > best2) best2 = rem;
						cur = cnt[cur] >= 2 ? cur : prv[cur - 1];
						if (cur != -1 && cur >= nlim) {
							rem = cur - nlim;
							if (best1 == -1 || rem > best1) best2 = best1, best1 = rem; else if (best2 == -1 || rem > best2) best2 = rem;
						}
					}
					if (best1 != -1 && best2 != -1) {
						ll x = min(have - take, (ll)(take / 2) * y + best2);
						if (x >= 2) ret = max(ret, x * y);
						//printf("\tBtake %d -> %lld -> %lld\n", take, x, x * y);
					}
					lim = nlim;
				} else {
					int nlim = (take / 2) * y;
					int cur = prv[lim - 1];
					if (best1 != -1 && best2 != -1) {
						ll x = min(have - take, (ll)(take / 2) * y + best1);
						if (x >= 2) ret = max(ret, x * y);
						//printf("\tCtake %d -> %lld -> %lld\n", take, x, x * y);
					}
					if (cur != -1 && cur >= nlim && best1 != -1) {
						int rem = cur - nlim;
						ll x = min(have - take, (ll)(take / 2) * y + rem);
						if (x >= 2) ret = max(ret, x * y);
						//printf("\tDtake %d -> %lld -> %lld\n", take, x, x * y);
					}
				}
			}
		}
	}

	return ret;
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}