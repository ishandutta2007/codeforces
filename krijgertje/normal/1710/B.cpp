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

template<class T> struct RMQSparse {
	const T* a; int n;
	vector<int> lg;
	vector<vector<int>> jmp;
	void init(const T* _a, int _n) {
		a = _a; n = _n; if (n < 1) return;
		lg = vector<int>(n + 1); lg[1] = 0; FORE(i, 2, n) lg[i] = lg[i >> 1] + 1;
		jmp = vector<vector<int>>(lg[n] + 1); jmp[0] = vector<int>(n); REP(i, n) jmp[0][i] = i;
		FORE(k, 1, lg[n]) { jmp[k] = vector<int>(n - (1 << k) + 1); REPE(i, n - (1 << k)) { int x = jmp[k - 1][i], y = jmp[k - 1][i + (1 << (k - 1))]; jmp[k][i] = a[y] > a[x] ? y : x; } }
	}
	void init(const vector<T>& a) { init(a.data(), SZ(a)); }
	int query(int l, int r) { int k = lg[r - l + 1]; int x = jmp[k][l], y = jmp[k][r - (1 << k) + 1]; return a[y] > a[x] ? y : x; }
};

const int MAXDAY = 200000;

int nday, lim;
int center[MAXDAY], intensity[MAXDAY];
bool ans[MAXDAY];

void solve() {
	vector<int> x;
	REP(i, nday) {
		x.PB(center[i] - intensity[i]);
		x.PB(center[i]);
		x.PB(center[i] + intensity[i]);
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	int nx = SZ(x);
	vector<int> delta(nx, 0);
	REP(i, nday) {
		delta[lower_bound(x.begin(), x.end(), center[i] - intensity[i]) - x.begin()] += 1;
		delta[lower_bound(x.begin(), x.end(), center[i]) - x.begin()] -= 2;
		delta[lower_bound(x.begin(), x.end(), center[i] + intensity[i]) - x.begin()] += 1;
	}
	vector<ll> y(nx);
	{
		ll cur = 0; int curdelta = 0;
		REP(i, nx) {
			if (i != 0) cur += (ll)curdelta * (x[i] - x[i - 1]);
			y[i] = cur;
			curdelta += delta[i];
		}
	}
	//printf("y:"); REP(i, nx) printf(" %d=%lld", x[i], y[i]); puts("");
	vector<ll> excess(nx);
	REP(i, nx) excess[i] = max(0LL, y[i] - lim);
	//printf("excess:"); REP(i, nx) printf(" %d=%lld", x[i], excess[i]); puts("");

	// 0<=z<=intensity[i]: v[center[i]-intensity[i]+z]-(center[i]-intensity[i]+z) <= -(center[i]-intensity[i]), v[center[i]+intensity[i]-z]+(center[i]+intensity[i]-z) <= center[i]+intensity[i]
	vector<ll> a(nx), b(nx);
	REP(i, nx) a[i] = excess[i] - x[i], b[i] = excess[i] + x[i];
	RMQSparse<ll> rmqexcess, rmqa, rmqb;
	rmqexcess.init(excess), rmqa.init(a), rmqb.init(b);

	REP(i, nday) {
		int l = lower_bound(x.begin(), x.end(), center[i] - intensity[i]) - x.begin();
		int m = lower_bound(x.begin(), x.end(), center[i]) - x.begin();
		int r = lower_bound(x.begin(), x.end(), center[i] + intensity[i]) - x.begin();
		ans[i] = excess[rmqexcess.query(0, l)] <= 0 && a[rmqa.query(l, m)] <= -(center[i] - intensity[i]) && b[rmqb.query(m, r)] <= center[i] + intensity[i] && excess[rmqexcess.query(r, nx - 1)] <= 0;
	}
}

void run() {
	scanf("%d%d", &nday, &lim);
	REP(i, nday) scanf("%d%d", &center[i], &intensity[i]);
	solve();
	REP(i, nday) printf("%c", ans[i] ? '1' : '0'); puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}