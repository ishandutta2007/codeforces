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

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];

int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	int ret = 0;
	for (int empty = n % 2; empty + empty - 1 <= n - 1; empty += 2) {
		int cur = (ll)2 * n % MOD * choose(n - 1 - empty - (empty - 1) + empty, empty) % MOD * fac[n - 1 - empty] % MOD;
		ret = (ret + cur) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	printf("%d\n", solve());
}

void research1() {
	int lim = 100;
	vector<int> same(lim + 1);
	vector<int> diff(lim + 1);
	same[0] = -1;
	diff[0] = 0;
	FORE(i, 1, lim) {
		//same
		{
			set<int> seen;
			REP(j, i) {
				//A
				if (j != 0 && j != i - 1) seen.insert(same[j] ^ same[i - j - 1]);
				//B
				seen.insert(diff[j] ^ diff[i - j - 1]);
			}
			same[i] = 0; while (seen.count(same[i])) ++same[i];
		}
		//diff
		{
			set<int> seen;
			REP(j, i) {
				//A
				if (j != 0) seen.insert(same[j] ^ diff[i - j - 1]);
				//B
				if (j != i - 1) seen.insert(diff[j] ^ same[i - j - 1]);
			}
			diff[i] = 0; while (seen.count(diff[i])) ++diff[i];
		}
	}
	printf("same:"); REPE(i, lim) printf(" %d", same[i]); puts("");
	printf("diff:"); REPE(i, lim) printf(" %d", diff[i]); puts("");

}

void research2() {
	FORE(n, 2, 6) {
		map<string, ll> ways;
		queue<string> q;
		auto inc = [&](const string& s, ll by) { if (!ways.count(s)) q.push(s); ways[s] += by;  };
		inc("A" + string(n - 1, '.') + "A", 1);
		inc("B" + string(n - 1, '.') + "B", 1);
		ll total = 0;
		while (!q.empty()) {
			string at = q.front();
			q.pop();
			bool any = false;
			ll by = ways[at];
			//printf("n=%d at=%s by=%lld\n", n, at.c_str(), by);
			REPSZ(i, at) if (at[i] == '.') for (char c = 'A'; c <= 'B'; ++c) {
				if (at[i - 1] == c || at[i + 1] == c) continue;
				string to = at;
				to[i] = c;
				inc(to, by);
				any = true;
			}
			if (!any) {
				int empty = 0;
				REPSZ(i, at) if (at[i] == '.') ++empty;
				printf("empty=%d\n", empty);
				assert(empty % 2 == n % 2);
				if(empty==2) total += by;
			}
		}
		printf("%d: %lld\n", n, total);
	}
}

int main() {
	//research1();
	//research2();
	run();
	return 0;
}