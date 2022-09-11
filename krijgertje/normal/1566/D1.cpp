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

const int MAXH = 300;
const int MAXW = 300;
const int MAXN = MAXH * MAXW;

int h, w, n;
int a[MAXN];

int v[MAXN], nv;
int b[MAXN];

int c[MAXN];
vector<vector<pair<int, int>>> pos;

int solve() {
	nv = 0; REP(i, n) v[nv++] = a[i];
	sort(v, v + nv); nv = unique(v, v + nv) - v;
	REP(i, n) b[i] = lower_bound(v, v + nv, a[i]) - v;
	REP(i, n) c[i] = b[i];
	sort(c, c + n);
	pos = vector<vector<pair<int, int>>>(nv);
	REP(i, n) pos[c[i]].PB(MP(i / w, i % w));
	REP(i, nv) {
		vector<pair<int, int>>& cur = pos[i];
		int suff = -1, pref = -1;
		assert(SZ(cur) >= 1);
		if (cur[0].second != 0) suff = cur[0].first;
		if (cur[SZ(cur) - 1].second != w - 1) pref = cur[SZ(cur) - 1].first;
		if (suff == pref) {
			reverse(cur.begin(), cur.end());
		} else {
			sort(cur.begin(), cur.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
				if ((a.first == suff) != (b.first == suff)) return a.first == suff;
				if ((a.first == pref) != (b.first == pref)) return b.first == pref;
				if (a.first != b.first) return a.first < b.first;
				return a.second > b.second;
			});
		}
		//printf("%d:", v[i]); for (auto z : cur) printf(" (%d,%d)", z.first, z.second); puts("");
	}
	int ret = 0;
	vector<vector<bool>> filled(h, vector<bool>(w, false));
	vector<int> at(nv, 0);
	REP(i, n) {
		pair<int, int> now = pos[b[i]][at[b[i]]++];
		//printf("(%d,%d)\n", now.first, now.second);
		assert(now.first >= 0 && now.first < h&& now.second >= 0 && now.second < w);
		assert(!filled[now.first][now.second]);
		REP(y, now.second) if (filled[now.first][y]) ++ret;
		filled[now.first][now.second] = true;
	}
	return ret;
}

void run() {
	scanf("%d%d", &h, &w); n = h * w;
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}