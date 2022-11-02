#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<bitset>
#include<numeric>
#include<climits>
#include<cassert>
#include<complex>
#include<functional>
using namespace std;

typedef long long ll;
template<typename A,typename B>inline void chmin(A &a, B b) { if (a > b)a = b; }
template<typename A,typename B>inline void chmax(A &a, B b) { if (a < b)a = b; }

const ll INF = 1001001001001001001ll;
ll memo[31][31][51];

ll dfs(int n, int m, int k) {
	ll &ret = memo[n][m][k];
	if (ret != -1)return ret;

	if (n*m < k)return INF;
	if (n*m == k||k==0)return 0;

	ret = INF;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			ret = min(ret, dfs(i, m, j) + dfs(n - i, m, k - j)+m*m);
		}
	}
	
	for (int i = 1; i < m; i++) {
		for (int j = 0; j <= k; j++) {
			ret = min(ret, dfs(n, i, j) + dfs(n, m - i, k - j)+n*n);
		}
	}

	return ret;
}

int main() {
	memset(memo, -1, sizeof(memo));
	int T; scanf("%d", &T);
	while (T--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		printf("%lld\n", dfs(n, m, k));
	}

	return 0;
}