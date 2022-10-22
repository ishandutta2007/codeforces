#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const ll Inf = 9000000000000000000ll;

int n, k;
ll sum[Maxn];
ll add[Maxn];
vector <int> V;
ll res = -Inf;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		V.push_back(a);
	}
	sort(V.rbegin(), V.rend());
	sum[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		sum[i] = sum[i + 1] + ll((n - 1 - i) / (k + 1)) * V[i]; 
	ll cur = 0;
	ll add = 0;
	for (int i = 0; i < n; i++) {
		int lft = (n - i - 1) / (k + 1) + 1;
		res = max(res, add + ll(cur) * lft + sum[i]);
		add += cur;
		cur += V[i];
	}
	res = max(res, add);
	printf("%I64d\n", res);
    return 0;
}