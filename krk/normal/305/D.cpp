#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const ll mod = 1000000007ll;
const int Maxn = 1000005;

int pw2[Maxn];
int n, m, k;
vector <int> neigh[Maxn];
bool st[Maxn];
int sum[Maxn];
int res = 1;

int main()
{
	pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) pw2[i] = 2 * pw2[i - 1] % mod;
	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
	}
	for (int i = n - 1; i >= 1; i--) {
		int j;
		for (j = 0; j < neigh[i].size(); j++)
			if (neigh[i][j] != i + 1 && neigh[i][j] != i + k + 1) break;
		if (j < neigh[i].size()) { res = 0; break; }
		if (i + k + 1 <= n && neigh[i].size() && neigh[i].back() == i + k + 1) st[i] = true;
	}
	if (res == 0) printf("0\n");
	else {
		for (int i = 1; i + k + 1 <= n; i++)
			sum[i] += sum[i - 1] + st[i];
		res = n - k - 1 < 1 || sum[n - k - 1] == 0;
		for (int i = 1; i <= k && i + k + 1 <= n; i++)
			if (sum[i] == sum[n - k - 1]) res = (res + pw2[i - 1 - sum[i - 1]]) % mod;
		for (int i = k + 1; i + k + 1 <= n; i++)
			if (sum[i] == sum[n - k - 1] && sum[i - k - 1] == 0) res = (res + pw2[k - sum[i - 1]]) % mod;
		printf("%d\n", res);
	}
	return 0;
}