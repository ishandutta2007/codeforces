#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;
const int Inf = 1000000000;

int T;
int n;
int a[Maxn];
deque <ii> dp[Maxn];
int add[Maxn];

void Add(deque <ii> &D, ii val)
{
	if (D.empty() || val.second < D.front().second)
		D.push_front(val);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		dp[n].clear(); add[n] = 0;
		dp[n].push_back(ii(n + 1, 0));
		for (int i = n - 1; i > 0; i--) {
			dp[i].clear();
			add[i] = 0;
			for (int j = n; j > i; j--) if (!dp[j].empty() && i + a[i] >= j) {
				int ind = lower_bound(dp[j].begin(), dp[j].end(), ii(i + a[i] + 1, 0)) - dp[j].begin();
				if (ind < dp[j].size())
					Add(dp[i], ii(j, add[j] + dp[j][ind].second));
				add[j]++;
			}
		}
		printf("%d\n", add[1] + dp[1].front().second);
	}
    return 0;
}