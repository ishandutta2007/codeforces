#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = 5000000000005ll;
const ll Inf = 4000000000000000000ll;
const int Maxn = 55;

int n;
int a[Maxn];
int b[Maxn];
vector <int> un;
vector <int> my[Maxn];
ll dp[Maxn][Maxn];

bool Check(ll x)
{
	fill((ll*)dp, (ll*)dp + Maxn * Maxn, -Inf);
	dp[un.size()][0] = 0;
	for (int i = int(un.size()) - 1; i >= 0; i--) {
		ll add1 = 0, add2 = 0;
		for (int j = 0; j <= my[i].size(); j++) {
			int use = int(my[i].size()) - j;
			for (int k = use; k < Maxn; k++) {
				int nj = k - use + j;
				dp[i][nj] = max(dp[i][nj], dp[i + 1][k] + max(add1, add2));
			}
			if (j < my[i].size()) {
				add1 += x * ll(my[i][j]) - ll(1000) * ll(un[i]);
				add2 += x * ll(my[i][int(my[i].size()) - 1 - j]) - ll(1000) * ll(un[i]);
			}
		}
	}
	for (int j = 0; j < Maxn; j++)
		if (dp[0][j] >= 0) return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		un.push_back(a[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
		my[ind].push_back(b[i]);
	}
	for (int i = 0; i < un.size(); i++)
		sort(my[i].rbegin(), my[i].rend());
	ll lef = 0, rig = lim;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Check(mid)) rig = mid - 1;
		else lef = mid + 1;
	}
	cout << rig + 1 << endl;
	return 0;
}