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

const int MAXN = 200000;

int n;
vector<int> a;
vector<int> b;

ll solve() {
	int save = 0;
	REP(rep, 2) {
		vector<pair<int, int>> oa(n);
		REP(i, n) oa[i] = MP(a[i], i);
		sort(oa.begin(), oa.end());
		vector<pair<int, int>> ob(n);
		REP(i, n) ob[i] = MP(b[i], i);
		sort(ob.begin(), ob.end());
		int j = 0;
		int mx = INT_MIN;
		REP(i, n) {
			while (j < n && ob[j].first <= oa[i].first) {
				mx = max(mx, a[ob[j].second]);
				++j;
			}
			int idx = oa[i].second;
			if (b[idx] > a[idx] && mx > a[idx]) {
				int cur = min(b[idx], mx) - a[idx];
				save = max(save, cur);
			}
		}
		swap(a, b);
	}
	//printf("save=%d\n", save);
	ll ret = 0;
	REP(i, n) ret += abs(a[i] - b[i]);
	ret -= 2 * save;
	return ret;
}

void run() {
	scanf("%d", &n);
	a = vector<int>(n); REP(i, n) scanf("%d", &a[i]);
	b = vector<int>(n); REP(i, n) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}

void research() {
	string s = "vwxy";
	do {
		// |v-w|+|x-y| vs |v-y|+|x-w|
		map<char, int> pos;
		REPSZ(i, s) pos[s[i]] = i;
		if (pos['v'] > pos['x']) continue;

		map<char, int> coef;
		auto upd = [&](char a, char b, int by) { if (pos[a] > pos[b]) swap(a, b); coef[b] += by, coef[a] -= by; };
		upd('v', 'w', +1);
		upd('x', 'y', +1);
		upd('v', 'y', -1);
		upd('x', 'w', -1);
		printf("%s:", s.c_str()); for (auto it = coef.begin(); it != coef.end(); ++it) if (it->second != 0) printf(" %c=%d", it->first, it->second); puts("");

	} while (next_permutation(s.begin(), s.end()));
}

int main() {
	run();
	//research();
	return 0;
}