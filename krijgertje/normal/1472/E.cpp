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
struct Item { int a, b, id; bool flipped; Item() {} Item(int a, int b, int id, bool flipped) :a(a), b(b), id(id), flipped(flipped) {} };
bool operator<(const Item& p, const Item& q) { if (p.a != q.a) return p.a < q.a; return p.b > q.b; }

int n;
int a[MAXN], b[MAXN];
int ans[MAXN];

Item item[2 * MAXN]; int nitem;

void solve() {
	nitem = 0;
	REP(i, n) item[nitem++] = Item(a[i], b[i], i, false), item[nitem++] = Item(b[i], a[i], i, true);
	sort(item, item + nitem);

	REP(i, n) ans[i] = -1;
	int best = -1;
	REP(i, nitem) {
		if (ans[item[i].id] == -1 && best != -1 && item[best].b < item[i].b) {
			assert(item[best].a < item[i].a);
			assert(item[best].id != item[i].id);
			ans[item[i].id] = item[best].id;
		}
		if (!item[i].flipped && (best == -1 || item[i].b < item[best].b)) best = i;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &a[i], &b[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] == -1 ? -1 : ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)  run();
	return 0;
}