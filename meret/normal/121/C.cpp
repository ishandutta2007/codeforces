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

int n, k;

set<LL> lucky;

void getLucky(LL x) {
	if (x > n) {
		return;
	}
	if (x != 0) {
		lucky.insert(x);
	}

	getLucky(x * 10 + 4);
	getLucky(x * 10 + 7);
}

LL fact[20];

bool used[20];


int main() {
	scanf("%d %d", &n, &k);

	int m = 1;
	fact[0] = fact[1] = 1;

	while (fact[m] < k) {
		++m;
		fact[m] = fact[m - 1] * m;
	}

	if (m > n) {
		printf("-1\n");
		return 0;
	}

	getLucky(0);

	int result = 0;

	FORE (it, lucky) {
		if (*it <= n - m) {
			++result;
		}
	}

	for (int i = 1; i <= m; ++i) {
		int c = 1;
		while (fact[m - i] < k) {
			k -= fact[m - i];
			++c;
		}
		for (int j = 1; j <= m; ++j) {
			if (!used[j]) {
				if (--c == 0) {
					if (lucky.find(n - m + i) != lucky.end() &&
						lucky.find(n - m + j) != lucky.end()) {
						++result;
					}
					used[j] = true;
					break;
				}
			}
		}
	}

	printf("%d\n", result);

    return 0;
}