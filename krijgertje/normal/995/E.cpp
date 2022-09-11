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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

int pw(int x, int n, int mod) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%mod; if ((n >>= 1) == 0) return ret; x = (ll)x*x%mod; } }
int inv(int x, int mod) { return pw(x, mod - 2, mod); }

vector<int> ans;
map<int, int> prv[2];
queue<pair<int,int> > q;

int invop(int x) { return x == 3 ? 3 : 3 - x; }

pair<int, vector<int> > reconstruct(int at, map<int,int> &prv, int p) {
	vector<int> path;
	while (true) {
		int op = prv[at];
		if (op == 0) {
			reverse(path.begin(), path.end());
			//printf("%d:", at); REPSZ(i, path) printf(" %d", path[i]); puts("");
			return MP(at, path);
		}
		path.PB(op);
		int iop = invop(op);
		int to = iop == 1 ? (at + 1) % p : iop == 2 ? (at + p - 1) % p : inv(at, p);
		at = to;
	}
}

bool solve(int s, int t, int p) {
	ans.clear(); prv[0].clear(); prv[1].clear(); q = queue<pair<int,int> >();
	if (s == t) return true;
	prv[0][s] = 0, prv[1][t] = 0; q.push(MP(0, s)); q.push(MP(1, t));
	while (!q.empty()) {
		int side = q.front().first, at = q.front().second; q.pop();
		FORE(op, 1, 3) {
			int to = op == 1 ? (at + 1) % p : op == 2 ? (at + p - 1) % p : inv(at, p);
			if (prv[side].count(to)) continue;
			//printf("%d: %d -> %d with %d\n", side, at, to, op);
			if (prv[1-side].count(to)) {
				pair<int, vector<int> > a = reconstruct(at, prv[side], p);
				pair<int, vector<int> > b = reconstruct(to, prv[1-side], p);
				bool swapped = false;
				if (a.first == t) swap(a, b), swapped = true;
				assert(a.first == s&&b.first == t);
				REPSZ(i, a.second) ans.PB(a.second[i]);
				ans.PB(!swapped ? op : invop(op));
				for (int i = SZ(b.second) - 1; i >= 0; --i) ans.PB(invop(b.second[i]));
				return true;
			}
			prv[side][to] = op; q.push(MP(side, to));
		}
	}
	return false;
}

void run() {
	int s, t, p;
	scanf("%d%d%d", &s, &t, &p);
	assert(solve(s, t, p));

	int x = s; REPSZ(i, ans) { int op = ans[i]; x = op == 1 ? (x + 1) % p : op == 2 ? (x + p - 1) % p : inv(x, p); } fprintf(stderr, "have=%d want=%d\n", x, t);

	printf("%d\n", SZ(ans)); REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}