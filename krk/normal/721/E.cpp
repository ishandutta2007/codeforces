#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int L, n, p, t;
ii lr[Maxn];
int dp[Maxn];
int en[Maxn], mor[Maxn];

int Get(int x)
{
	int ind = lower_bound(lr, lr + n, ii(x + 1, 0)) - lr - 1;
	if (ind < 0 || lr[ind].second < x) ind++;
	if (ind >= n) return 0;
	if (x < lr[ind].first) return dp[ind];
	int res = (lr[ind].second - x) / p + en[ind];
	if ((lr[ind].second - x) % p >= mor[ind]) res++;
	return max(dp[ind + 1], res);
}

int main()
{
	scanf("%d %d %d %d", &L, &n, &p, &t);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &lr[i].first, &lr[i].second);
	for (int i = n - 1; i >= 0; i--) {
		en[i] = Get(lr[i].second + t);
		int l = 1, r = min(p - 1, lr[i].second - lr[i].first);
		mor[i] = p;
		while (l <= r) {
			int mid = l + r >> 1;
			if (Get(lr[i].second - mid + t) > en[i]) r = mid - 1;
			else l = mid + 1;
		}
		mor[i] = l;
		int cand = (lr[i].second - lr[i].first) / p + en[i];
		if ((lr[i].second - lr[i].first) % p >= mor[i]) cand++;
		dp[i] = max(dp[i + 1], cand);
	}
	printf("%d\n", dp[0]);
    return 0;
}