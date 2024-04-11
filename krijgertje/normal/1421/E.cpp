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

int n;
vector<int> a;

ll solve() {
	int offset = 2 - n % 3;
	vector<int> b = a; sort(b.begin(), b.end());
	vector<ll> bsum(n + 1); bsum[0] = 0; REP(i, n) bsum[i + 1] = bsum[i] + b[i];
	int mneven = INT_MAX; for (int i = 0; i < n; i += 2) mneven = min(mneven, a[i]);
	int mxodd = INT_MIN; for (int i = 1; i < n; i += 2) mxodd = max(mxodd, a[i]);
	
	ll ret = LLONG_MIN;
	for (int pos = offset; pos <= n; pos += 3) {
		ll cur = (bsum[n] - bsum[n - pos]) - (bsum[n - pos] - bsum[0]);
		if (n % 2 == 1 && n >= 3 && pos == (n + 1) / 2 && mneven > mxodd) {
			cur -= 2 * (mneven - mxodd);
		}
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	a = vector<int>(n); REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

void research() {
	vector<vector<int>> choose(20, vector<int>(20, 0)); REPSZ(i, choose) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j]; }
	for (int n = 1; n <= 16; ++n) {
		set<vector<string>> seen;
		queue<vector<string>> q;
		vector<string> start(n, "+");
		seen.insert(start); q.push(start);
		vector<string> res;
		while (!q.empty()) {
			vector<string> at = q.front(); q.pop();
			if (SZ(at) == 1) { res.PB(at[0]); continue; }
			FORSZ(i, 1, at) {
				vector<string> to = at; to.erase(to.begin() + i); to[i - 1] += at[i]; REPSZ(j, to[i - 1]) to[i - 1][j] = to[i - 1][j] == '+' ? '-' : '+';
				if (!seen.count(to)) seen.insert(to), q.push(to);
			}
		}
		//sort(res.begin(), res.end());
		//REPSZ(i, res) cout << res[i] << endl;
		vector<int> ways(n + 1, 0); REPSZ(i, res) { int cnt = 0; REPSZ(j, res[i]) if (res[i][j] == '+') ++cnt; ++ways[cnt]; }
		printf("ways%d:", n); REPSZ(i, ways) if (ways[i] > 0) printf(" %d=%d/%d", i, ways[i], choose[n][i]); puts("");
	}
}

int main() {
	//research();
	run();
	return 0;
}