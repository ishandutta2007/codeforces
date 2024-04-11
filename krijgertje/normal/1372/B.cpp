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
int ans[2];

void solve() {
	vector<int> gcand;
	for (int i = 1; (ll)i * i <= n; ++i) if(n%i==0) {
		gcand.PB(i);
		gcand.PB(n / i);
	}
	sort(gcand.begin(), gcand.end()); gcand.erase(unique(gcand.begin(), gcand.end()), gcand.end());
	ll best = LLONG_MAX;
	REPSZ(i, gcand) {
		int g = gcand[i]; if (g >= n) continue;
		int sum = n / g;
		int a = 1, b = sum - 1;
		ll cur = (ll)g * a * b;
		if (cur < best) best = cur, ans[0] = a * g, ans[1] = b * g;
	}
}

void run() {
	scanf("%d", &n);
	solve();
	printf("%d %d\n", ans[0], ans[1]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}