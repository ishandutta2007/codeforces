#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int MD = (int) 1e9 + 7;

int k;

int fact[1000005];
int rfact[1000005];
int rev[1000005];

inline int mn(int a, int b) {
	return (a * (LL) b) % MD;
}

inline int sq(int a) {
	return mn(a, a);
}

int pot(int a, int b) {
	int res = 1;
	for (; b > 0; b >>= 1) {
		if (b & 1) {
			res = mn(res, a);
		}
		a = mn(a, a);
	}
	return res;
}

int chooseo(int a, int b) {
	return mn(fact[b], rfact[b - a]);
}

int count(int len, int diff) {
	if (2 * diff <= len) {
		return mn(sq(chooseo(diff, k)), pot(k, len - 2 * diff));
	} else {
		return mn(chooseo(diff, k), chooseo(len - diff, k - (2 * diff - len)));
	}
}

void ad(int& a, LL b) {
	a = ((a + b) % MD + MD) % MD;
}

int main() {
	int w;
	scanf("%d %d", &k, &w);
	fact[0] = rfact[0] = 1;
	rev[1] = 1;
	for (int i = 2; i <= k; ++i) {
		rev[i] = mn(MD - MD / i, rev[MD % i]);
	}
	for (int i = 1; i <= k; ++i) {
		fact[i] = mn(i, fact[i - 1]);
		rfact[i] = mn(rev[i], rfact[i - 1]);
	}
	int res = 0;
	for (int append = 0; append <= k; ++append) {
		ad(res, count(w + append, append));
		if (append < k) {
			ad(res, -count(w + append, append + 1));
		}
	}
	printf("%d\n", res);
}