#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n;

vector<int> p;
void calcp() { p.clear(); int x = n; for (int i = 2; (ll)i*i <= x; ++i) if (x%i == 0) { p.PB(i); while (x%i == 0) x /= i; } if (x != 1) p.PB(x); }

int mod;
vector<int> act;
vector<ll> d;
priority_queue<pair<ll, int>> pq;
vector<int> num;
vector<pair<int, int>> ans;

bool solve() {
	calcp();
	//printf("p:"); REPSZ(i, p) printf(" %d", p[i]); puts("");
	
	if (SZ(p) < 2) return false;
	mod = p[0];
	d = vector<ll>(mod, LLONG_MAX);
	act = vector<int>(mod, -1);
	pq = priority_queue<pair<ll, int>>();
	d[0] = 0, act[0] = -2, pq.push(MP(-d[0], 0));
	while (!pq.empty()) {
		ll cost = -pq.top().first; int at = pq.top().second; pq.pop();
		if (cost != d[at]) continue;
		FORSZ(i, 1, p) {
			int to = (at + p[i]) % mod; ll ncost = cost + p[i];
			if (ncost < d[to]) d[to] = ncost, act[to] = i, pq.push(MP(-d[to], to));
		}
	}
	//printf("d:"); REP(i, mod) printf(" %lld", d[i]); puts("");
	if (d[mod - 1] > n - 1) return false;
	num = vector<int>(SZ(p), 0);
	num[0] = (n - 1 - d[mod - 1]) / mod;
	for (int at = mod - 1; at != 0; at = ((at - p[act[at]]) % mod + mod) % mod) ++num[act[at]];
	//printf("num:"); REPSZ(i, num) printf(" %d", num[i]); puts("");
	ans.clear(); REPSZ(i, p) if (num[i] != 0) ans.PB(MP(num[i], n / p[i]));
	return true;
}

void run() {
	scanf("%d", &n);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first, ans[i].second);
}

int main() {
	run();
	return 0;
}