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

int MD;

LL countS(LL suf, LL p2, LL n) {
	if (n <= suf) {
		return 0LL;
	}
	return (n - suf + p2 - 1) / p2;
}

LL mn(LL a, LL b) {
	return (a % MD) * (b % MD) % MD;
}

LL sum(LL c) {
	if (c % 2) {
		return mn(c, (c - 1) / 2);
	} else {
		return mn(c / 2, c - 1);
	}
}

LL F(LL suf, LL p2, LL cnt, LL n) {
	if (cnt == 0) {
		return 0;
	}
	if (countS(suf, p2, n) == cnt) {
		return (mn(sum(cnt), p2) + mn(suf, cnt) + cnt) % MD;
	} else {
		if (countS(suf, p2 * 2, n) >= cnt) {
			return F(suf, p2 * 2, cnt, n);
		} else {
			return (F(suf, p2 * 2, countS(suf, p2 * 2, n), n) + F(suf + p2, p2 * 2, cnt - countS(suf, p2 * 2, n), n)) % MD;
		}
	}
}

LL findUB(LL cnt, LL m, LL n) {
	LL p2 = 1;
	LL suf = 0;
	LL rem = cnt;
	LL rcnt = 0;
	for (int i = 0; i < 61; ++i) {
		if (countS(suf, p2 * 2, n) < rem) {
			rcnt += countS(suf, p2 * 2, m);
			rem -= countS(suf, p2 * 2, n);
			suf += p2;
		}
		p2 *= 2;
	}
	rcnt += countS(suf, p2, m);
	return rcnt;
}

LL get(LL cnt, LL m, LL n) {
	if (cnt == 0 || m == 0) {
		return 0LL;
	}
	cnt = findUB(cnt, m, n);
	return F(0, 1, cnt, m);
}

LL n;

int main() {
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m >> MD;

	for (int i = 1; i <= m; ++i) {
		LL l, r, u, v;
		cin >> l >> r >> u >> v;
		if (u > n) {
			cout << "0\n";
			continue;
		}
		v = min(v, n);
		LL res = get(r, v, n) - get(r, u - 1, n) - get(l - 1, v, n) + get(l - 1, u - 1, n);
		cout << ((res % MD) + MD) % MD << "\n";
	}

    return 0;
}