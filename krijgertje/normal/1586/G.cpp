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
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
struct Task { int a, b; bool isneeded; };

int n;
Task task[MAXN];
vector<int> need;

int dp[MAXN];
int nextneeded[MAXN];

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	void mod(int idx, int by) { ++idx; while (idx > 0) { inc(val[idx], by); idx -= idx & -idx; } }
	int get(int idx) { ++idx; int ret = 0; while (idx <= n) { inc(ret, val[idx]); idx += idx & -idx; } return ret; }
};
BIT bit;

int solve() {
	REP(i, n) task[i].isneeded = false;
	for (int x : need) task[x].isneeded = true;
	sort(task, task + n, [](const Task& p, const Task& q) { return p.b < q.b; });
	int lastneeded = -1;
	for (int i = n - 1; i >= 0; --i) if (task[i].isneeded) {
		if (lastneeded != -1 && task[i].a < task[lastneeded].a) { task[i].isneeded = false; continue; }
		nextneeded[i] = lastneeded;
		lastneeded = i;
	}
	//printf("needed:"); REP(i, n) if (task[i].isneeded) printf(" %d-%d", task[i].a + 1, task[i].b + 1); puts("");

	int ret = 0;
	bit.init(2 * n);
	REP(i, n) {
		if (task[i].isneeded) {
			int cur = bit.get(nextneeded[i] == -1 ? 0 : task[nextneeded[i]].a + 1);
			inc(cur, 1);
			//printf("missing %d-%d -> %d\n", task[i].a + 1, task[i].b + 1, cur);
			inc(ret, cur);
		}
		dp[i] = bit.get(task[i].a + 1);
		inc(dp[i], 1);
		//printf("dp[%d-%d]=%d\n", task[i].a + 1, task[i].b + 1, dp[i]);
		bit.mod(task[i].a, dp[i]);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &task[i].a, &task[i].b), --task[i].a, --task[i].b;
	{ int cnt; scanf("%d", &cnt); need = vector<int>(cnt); REP(i, cnt) scanf("%d", &need[i]), --need[i]; }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}