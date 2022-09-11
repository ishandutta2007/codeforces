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

const int MAXPOINT = 200000;
const int MAXSEG = 200000;

int npoint, nseg;
int px[MAXPOINT];
pair<int, int> sx[MAXSEG];

int before[MAXSEG + 1];

ll freepointdp[MAXPOINT];
ll usedpointdp[MAXPOINT];
ll segdp[MAXSEG];

ll solve() {
	sort(px, px + npoint);
	sort(sx, sx + nseg, [&](const pair<int, int>& a, const pair<int, int>& b) { if (a.first != b.first) return a.first < b.first; return a.second > b.second; });
	{ int cnt = 0; REP(i, nseg) { while (cnt > 0 && sx[cnt - 1].second >= sx[i].second) --cnt; sx[cnt++] = sx[i]; } nseg = cnt; }
	{
		int cnt = 0, at = 0;
		REP(i, nseg) {
			while (at < npoint&& px[at] < sx[i].first) ++at;
			if (at < npoint && px[at] <= sx[i].second) continue;
			before[cnt] = at - 1;
			sx[cnt++] = sx[i];
		}
		before[cnt] = npoint - 1;
		nseg = cnt;
	}
	//printf("points:"); REP(i, npoint) printf(" %d", px[i]); puts("");
	//printf("segs:"); REP(i, nseg) printf(" (%d,%d)[%d]", sx[i].first, sx[i].second, before[i]); puts("");

	// relax segdp[i] with min(sx[i].first-px[before[i]]+sx[i].first-sx[j].second+segdp[j-1])	->	sx[i].first-px[before[i]]+sx[i].first+min(-sx[j].second+segdp[j-1]) A
	// relax segdp[i] with min(px[before[i]]-sx[j].second+sx[i].first-sx[j].second+segdp[j-1])	->	px[before[i]]+sx[i].first+min(-sx[j].second-sx[j].second+segdp[j-1]) B
	// relax segdp[i] with sx[i].first-px[before[i]]+pointdp[before[i]]
	// relax pointdp[k] with min(px[k]-sx[l].second+segdp[l-1])									->	px[k]+min(-sx[j].second+segdp[j-1]) C
	// relax pointdp[k] with last segdp

	ll A = LLONG_MAX, B = LLONG_MAX, C = LLONG_MAX;
	int k = -1;
	int j = 0;
	ll ret = LLONG_MAX;
	auto relax = [&](ll& x, ll y) { x = min(x, y); };
	REPE(i, nseg) {
		if (k < before[i]) while (j < i) {
			ll pref = j == 0 ? 0 : before[j - 1] == before[j] ? segdp[j - 1] : usedpointdp[before[j]];
			if (pref != LLONG_MAX) {
				relax(A, (ll)-sx[j].second + pref);
				relax(B, (ll)-sx[j].second - sx[j].second + pref);
				relax(C, (ll)-sx[j].second + pref);
			}
			++j;
		}
		while (k < before[i]) {
			++k;
			freepointdp[k] = usedpointdp[k] = LLONG_MAX;
			ll pref = i == 0 ? 0 : before[i - 1] == k - 1 ? segdp[i - 1] : usedpointdp[k - 1];
			relax(freepointdp[k], pref);
			if (C != LLONG_MAX) relax(usedpointdp[k], (ll)px[k] + C);
			relax(usedpointdp[k], freepointdp[k]);
			ret = usedpointdp[k];
			//printf("pointdp[%d]=%lld/%lld\n", k, freepointdp[k], usedpointdp[k]);
		}
		if (i == nseg) break;
		segdp[i] = LLONG_MAX;
		if (before[i] != -1) {
			if (A != LLONG_MAX) relax(segdp[i], (ll)sx[i].first - px[before[i]] + sx[i].first + A);
			if (B != LLONG_MAX) relax(segdp[i], (ll)px[before[i]] + sx[i].first + B);
			if (freepointdp[before[i]] != LLONG_MAX) relax(segdp[i], (ll)sx[i].first - px[before[i]] + freepointdp[before[i]]);
		}
		ret = segdp[i];
		//printf("segdp[%d]=%lld [%lld,%lld->%lld,%lld,%lld]\n", i, segdp[i], A, B, (ll)sx[i].first - px[before[i]] + sx[i].first + A, (ll)px[before[i]] + sx[i].first + B, (ll)sx[i].first - px[before[i]] + freepointdp[before[i]]);
	}
	return ret;
}

void run() {
	scanf("%d%d", &npoint, &nseg);
	REP(i, npoint) scanf("%d", &px[i]);
	REP(i, nseg) scanf("%d%d", &sx[i].first, &sx[i].second);
	printf("%lld\n", solve());
}

ll solvestupid() {
	auto relax = [&](ll& x, ll y) { x = min(x, y); };
	vector<ll> dp(1 << nseg, LLONG_MAX);
	relax(dp[0], 0);
	REP(i, npoint) {
		for (int mask = (1 << nseg) - 1; mask >= 0; --mask) {
			if (dp[mask] == LLONG_MAX) continue;
			int rem = (1 << nseg) - 1 - mask;
			for (int me = 0;; me = (me + 1 + mask) & rem) {
				int l = px[i], r = px[i];
				REP(j, nseg) if (me & (1 << j)) {
					if (sx[j].second < px[i]) l = min(l, sx[j].second);
					if (sx[j].first > px[i]) r = max(r, sx[j].first);
				}
				relax(dp[mask | me], dp[mask] + r - l + min(r - px[i], px[i] - l));
				if (me == rem) break;
			}
		}
	}
	return dp[(1 << nseg) - 1];
}

void stress() {
	auto genx = [&]() { return rnd() % 100; };
	REP(rep, 1000) {
		npoint = rnd() % 10 + 1;
		nseg = rnd() % 10 + 1;
		REP(i, npoint) px[i] = genx();
		REP(i, nseg) { sx[i].first = genx(); sx[i].second = genx(); if (sx[i].first > sx[i].second) swap(sx[i].first, sx[i].second); }
		printf("%d %d\n", npoint, nseg);
		REP(i, npoint) { if (i != 0) printf(" "); printf("%d", px[i]); } puts("");
		REP(i, nseg) printf("%d %d\n", sx[i].first, sx[i].second);
		ll want = solvestupid();
		ll have = solve();
		if (have == want) { printf("."); continue; }
		printf("err have=%lld want=%lld\n", have, want);
		break;
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}