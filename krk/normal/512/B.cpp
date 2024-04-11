#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 305;
const int Inf = 1000000000;
const int Maxm = 1 << 13;

int n;
int l[Maxn], c[Maxn];
int mask[Maxn];
int dp[Maxm];
int res = Inf;

int Solve(int v)
{
	vector <int> pr;
	int num = l[v];
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) {
			pr.push_back(i);
			while (num % i == 0) num /= i;
		}
	if (num > 1) pr.push_back(num);
	for (int i = 0; i < n; i++) if (i != v) {
		mask[i] = 0;
		for (int j = 0; j < pr.size(); j++)
			if (l[i] % pr[j]) mask[i] |= 1 << j;
	}
	dp[0] = 0;
	for (int i = 1; i < 1 << pr.size(); i++)
		dp[i] = Inf;
	for (int i = 0; i + 1 < 1 << pr.size(); i++)
		for (int j = 0; j < n; j++) if (j != v)
			dp[i | mask[j]] = min(dp[i | mask[j]], dp[i] + c[j]);
	return dp[(1 << pr.size()) - 1] + c[v];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &l[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++)
		res = min(res, Solve(i));
	printf("%d\n", res < Inf? res: -1);
	return 0;
}