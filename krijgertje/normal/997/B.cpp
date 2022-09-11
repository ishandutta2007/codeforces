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

int n;

void run() {
	scanf("%d", &n);

	ll ret = 0;
	REPE(a, 5) REPE(b, 8) REPE(c, 4) REPE(d, 1) { // mx means >= mx
		if (a >= 5 && d >= 1) continue;
		if (b >= 8 && d >= 1) continue;
		if (a >= 5 && c >= 4) continue;
		int have = a + b + c + d;
		int cnt = (a >= 5 ? 1 : 0) + (b >= 8 ? 1 : 0) + (c >= 4 ? 1 : 0) + (d >= 1 ? 1 : 0);
		if (have > n || have < n&&cnt == 0) continue;
		if (cnt == 0) ++ret;
		if (cnt == 1) ++ret;
		if (cnt == 2) ret += n - have + 1;
	}
	printf("%lld\n", ret);
}

void norm(int &a, int &b, int &c, int &d) {
	while (a >= 5 && d >= 1) a -= 5, d -= 1, b += 1, c += 5;
	while (b >= 8 && d >= 1) b -= 8, d -= 1, c += 9;
	while (a >= 5 && c >= 4) a -= 5, c -= 4, b += 9;
}

void stress() {
	const int MAXN = 50;
	map<int, vector<int>> seen[MAXN + 1];
	REPE(n, MAXN) REPE(i, n) REPE(j, n - i) REPE(k, n - i - j) {
		int a = i, b = j, c = k, d = n - i - j - k;
		int v1 = a * 1 + b * 5 + c * 10 + d * 50;
		norm(a, b, c, d);
		int v2 = a * 1 + b * 5 + c * 10 + d * 50;
		assert(v1 == v2 &&a + b + c + d == n);
		vector<int> cur(4); cur[0] = a, cur[1] = b, cur[2] = c, cur[3] = d;
		//if (v1 == 60 && n == 11) printf("%d %d %d %d\n", a, b, c, d);
		if (seen[n].count(v1) && seen[n][v1] != cur) { printf("multiple ways to make %d with %d\n", v1, n); } else seen[n][v1] = cur;
	}
}

int main() {
	//stress();
	run();
	return 0;
}