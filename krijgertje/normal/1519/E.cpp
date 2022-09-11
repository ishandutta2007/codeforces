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
struct Frac { ll num, den; Frac() {} Frac(ll num) :num(num), den(1) {} Frac(ll num, ll den) :num(num), den(den) { normalize(); } void normalize() { assert(den != 0); if (den < 0) num = -num, den = -den; ll g = gcd(abs(num), den); num /= g, den /= g; } };
bool operator<(const Frac& a, const Frac& b) { if (a.num != b.num) return a.num < b.num; return a.den < b.den; }
Frac operator+(const Frac& a, const Frac& b) { return Frac(a.num * b.den + b.num * a.den, a.den * b.den); }
Frac operator/(const Frac& a, const Frac& b) { return Frac(a.num * b.den, a.den * b.num); }
struct P { Frac x, y; P() {} P(Frac x, Frac y) :x(x), y(y) {} };
P operator+(const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }

int n;
P p[MAXN];
vector<pair<int, int>> ans;

int nline;
map<Frac, int> linemp;
vector<Frac> lines;
vector<vector<pair<int, int>>> adj;

vector<int> par, parid, dep;
int dfs(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	//REP(i, dep[at]) printf(" "); printf("dfs(%d) [par=%d,parid=%d]\n", at, par[at], parid[at]);
	int ret = -1;
	for (auto z : adj[at]) {
		int to = z.first, id = z.second;
		if (id == parid[at]) continue;
		int sub = -1;
		if (par[to] == -2) {
			par[to] = at;
			parid[to] = id;
			sub = dfs(to);
		} else if (dep[to] < dep[at]) {
			sub = id;
		}
		if (sub != -1) {
			if (ret != -1) {
				ans.PB(MP(ret, sub));
				ret = -1;
			} else {
				ret = sub;
			}
		}
	}
	if (parid[at] != -1) {
		if (ret != -1) {
			ans.PB(MP(ret, parid[at]));
			ret = -1;
		} else {
			ret = parid[at];
		}
	}
	return ret;
}

void solve() {
	nline = 0;
	linemp.clear();
	lines.clear();
	adj.clear();
	auto getlineid = [&](const Frac& f) { if (linemp.count(f)) return linemp[f]; int ret = nline++; linemp[f] = ret; lines.PB(f); adj.PB(vector<pair<int, int>>()); return ret; };
	REP(i, n) {
		P a = p[i] + P(Frac(1), Frac(0));
		P b = p[i] + P(Frac(0), Frac(1));
		Frac fa = a.y / a.x;
		Frac fb = b.y / b.x;
		int aid = getlineid(fa);
		int bid = getlineid(fb);
		adj[aid].PB(MP(bid, i));
		adj[bid].PB(MP(aid, i));
	}
	//REP(i, nline) { printf("line%d:", i); for (auto z : adj[i]) printf(" (%d,%d)", z.first, z.second); puts(""); }

	ans.clear();
	par = vector<int>(nline, -2);
	parid = vector<int>(nline);
	dep = vector<int>(nline);
	REP(i, nline) if (par[i] == -2) { par[i] = -1, parid[i] = -1; dfs(i); }
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld%lld%lld%lld", &p[i].x.num, &p[i].x.den, &p[i].y.num, &p[i].y.den);
	REP(i, n) p[i].x.normalize(), p[i].y.normalize();
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	run();
	return 0;
}