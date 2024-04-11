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
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 2000;

int price[N], occ[N];

LL dp[N + 1];

int n;

int main() {
	LL sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> occ[i] >> price[i];
		sum += price[i];
	}
	for (int i = 1; i <= n; ++i)
		dp[i] = sum;
	for (int i = 0; i < n; ++i) {
		for (int j = n; j >= 0; --j) {
			dp[min(n, j + occ[i] + 1)] =
					min(dp[min(n, j + occ[i] + 1)],
							dp[j] + price[i]);
		}
	}
	cout << dp[n] << "\n";
}