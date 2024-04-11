#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int n;
ll l;
int k;
ii aind[Maxn];
int L[Maxn];
vector <vector <int> > dp;
int res;

int main()
{
	scanf("%d %I64d %d", &n, &l, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &aind[i].first);
		aind[i].second = i;
	}
	sort(aind, aind + n);
	for (int i = 0; i < n; i++)
		L[i] = (i == 0 || aind[i - 1].first == aind[i].first)? L[i - 1]: i;

	ll bef = l / n;

	dp.assign(k + 2, vector <int>(n + 2, 0)); 
	dp[1][0] = 1;
	for (int i = 1; i <= k; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum = (sum + dp[i][j]) % mod;

			if (aind[j].second < l % n)
				res = (res + max(0ll, bef + 1 - i + 1) % mod * sum % mod) % mod;
			else res = (res + max(0ll, bef - i + 1) % mod * sum % mod) % mod;

			dp[i + 1][L[j]] = (dp[i + 1][L[j]] + sum) % mod;
		}
	}
	printf("%d\n", res);
	return 0;
}