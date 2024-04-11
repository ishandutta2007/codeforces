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

const int MAXN = 100000;

int n;
int a[MAXN];
int b[MAXN];

bool done[MAXN];

void solve() {
	REP(i, n) done[i] = false;
	int rem = n;
	/*int lo = a[0], hi = a[0]; FOR(i, 1, n) lo = min(lo, a[i]), hi = max(hi, a[i]);
	vector<int> pos(hi - lo + 1, -1);
	REP(i, n) {
		int id = a[i] - lo;
		if (pos[id] != -1 && rem - 2 >= 2) {
			int j = pos[id];
			pos[id] = -1;
			done[i] = done[j] = true;
			b[i] = +1, b[j] = -1;
			rem -= 2;
		} else {
			pos[id] = i;
		}
	}*/
	vector<int> todo;
	REP(i, n) if (!done[i]) todo.PB(i);
	assert(SZ(todo) == rem);
	assert(SZ(todo) >= 2);
	if (SZ(todo) % 2 == 1) {
		assert(SZ(todo) >= 3);
		int x = todo.back(); todo.pop_back();
		int y = todo.back(); todo.pop_back();
		int z = todo.back(); todo.pop_back();
		if (a[x] > a[y]) swap(x, y); if (a[x] > a[z]) swap(x, z); if (a[y] > a[z]) swap(y, z);
		if (a[y] + a[z] == 0) swap(x, z);
		assert(a[y] + a[z] != 0);
		b[x] = -(a[y] + a[z]), b[y] = b[z] = a[x];
	}
	while (SZ(todo) != 0) {
		assert(SZ(todo) >= 2);
		int x = todo.back(); todo.pop_back();
		int y = todo.back(); todo.pop_back();
		b[x] = -a[y], b[y] = a[x];
	}
	ll sum = 0; REP(i, n) sum += (ll)a[i] * b[i]; assert(sum == 0);
	REP(i, n) assert(b[i] != 0);
	ll abssum = 0; REP(i, n) abssum += abs(b[i]); assert(abssum <= 1000000000);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", b[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}