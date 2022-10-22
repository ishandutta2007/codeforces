#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int n, c;
int a[Maxn];
int mn[Maxn];
map <int, int> M;
ll dp[Maxn];
ll sum = 0;

void Add(int x) { M[x]++; }

void Rem(int x)
{
	if (--M[x] == 0) M.erase(x);
}

int main()
{
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < c - 1; i++)
		Add(a[i]);
	for (int i = c - 1; i < n; i++) {
		Add(a[i]);
		mn[i - (c - 1)] = M.begin()->first;
		Rem(a[i - (c - 1)]);
	}
	fill(dp, dp + Maxn, -Inf); dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		if (i + c <= n) dp[i + c] = max(dp[i + c], dp[i] + mn[i]);
	}
	cout << sum - dp[n] << endl;
	return 0;
}