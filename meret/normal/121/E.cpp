//BEGIN_CUT
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <cstring>
#include <sstream>
#include <utility>
#include <queue>
#include <cassert>
using namespace std;

#define X first
#define Y second
#define FI first
#define SE second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }
//END_CUT

int nextEv[10005];
bool lucky[10005];

const int MX = 10000;

bool isLucky(int x) {
	while (x > 0) {
		if (x % 10 != 4 && x % 10 != 7) {
			return false;
		}
		x /= 10;
	}
	return true;
}

const int N = 400005;

int n;

int t[N];

void smad(int c, int a) {
	while (c <= n) {
		t[c] += a;
		c += c & -c;
	}
}

int smsm(int c) {
	int res = 0;
	while (c > 0) {
		res += t[c];
		c -= c & -c;
	}
	return res;
}

int ad[N];
int nextEvent[N];

inline int ls(int x) {
	return x << 1;
}

inline int rs(int x) {
	return (x << 1) + 1;
}

void inc(int x, int l, int r, int cl, int cr, int d) {
	int m = (l + r) / 2;
	if (l == cl && r == cr) {
		if (nextEvent[x] <= d) {
			if (l == r) {
				if (lucky[ad[x]]) {
					smad(l, -1);
				}
				ad[x] += d;
				nextEvent[x] = nextEv[ad[x]];
				if (lucky[ad[x]]) {
					smad(l, 1);
				}
			} else {
				ad[ls(x)] += ad[x];
				ad[rs(x)] += ad[x];
				nextEvent[ls(x)] -= ad[x];
				nextEvent[rs(x)] -= ad[x];
				ad[x] = 0;
				inc(ls(x), l, m, l, m, d);
				inc(rs(x), m + 1, r, m + 1, r, d);
				nextEvent[x] = min(nextEvent[ls(x)], nextEvent[rs(x)]);
			}
		} else {
			nextEvent[x] -= d;
			ad[x] += d;
		}
		return;
	}
	ad[ls(x)] += ad[x];
	ad[rs(x)] += ad[x];
	nextEvent[ls(x)] -= ad[x];
	nextEvent[rs(x)] -= ad[x];
	ad[x] = 0;
	if (cl <= m) {
		inc(ls(x), l, m, cl, min(cr, m), d);
	}
	if (cr > m) {
		inc(rs(x), m + 1, r, max(cl, m + 1), cr, d);
	}
	nextEvent[x] = min(nextEvent[ls(x)], nextEvent[rs(x)]);
}

int main() {

	nextEvent[MX] = 1;
	for (int i = 1; i <= MX; ++i) {
		lucky[i] = isLucky(i);
	}
	for (int i = MX - 1; i >= 1; --i) {
		if (lucky[i] || lucky[i + 1]) {
			nextEv[i] = 1;
		} else {
			nextEv[i] = 1 + nextEv[i + 1];
		}
	}

	int m;

	scanf("%d %d", &n, &m);


	int z = 1;
	while (z <= n) {
		z *= 2;
	}

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ad[z + i - 1]);
		if (lucky[ad[z + i - 1]]) {
			smad(i, 1);
		}
		nextEvent[z + i - 1] = nextEv[ad[z + i - 1]];
	}

	for (int i = z - 1; i >= 1; --i) {
		nextEvent[i] = min(nextEvent[ls(i)], nextEvent[rs(i)]);
	}

	for (int i = z + n; i < z + z; ++i) {
		nextEvent[i] = int(1e9) + 1;
	}

	for (int i = 1; i <= m; ++i) {

		char buf[8];
		int l, r;
		scanf("%s %d %d", buf, &l, &r);

		if (buf[0] == 'c') {
			printf("%d\n", smsm(r) - smsm(l - 1));
		} else {
			int d;
			scanf("%d", &d);
			inc(1, 1, z, l, r, d);
		}
	}



	return 0;
}