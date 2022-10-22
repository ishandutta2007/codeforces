#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 1005;

int n;
ll k;
vector <ll> facs, divs;
vector <vector <ll> > fdivs;
ll a[Maxn];
vector <ll> fa[Maxn];
vector <ill> dp[Maxn];
vector <int> par[Maxn];
vector <int> res;

int main()
{
	scanf("%d %I64d", &n, &k);

	for (ll i = 1; i * i <= k; i++)
		if (k % i == 0) {
			divs.push_back(i);
			if (i * i < k) divs.push_back(k / i);
		}
	sort(divs.begin(), divs.end());
	ll num = k;
	for (ll i = 2; i * i <= num; i++)
		if (num % i == 0) {
			facs.push_back(i);
			while (num % i == 0) num /= i;
		}
	if (num > 1) facs.push_back(num);
	fdivs.resize(divs.size());
	for (int i = 0; i < divs.size(); i++) {
		ll num = divs[i];
		for (int j = 0; j < facs.size(); j++) {
			ll cur = facs[j];
			ll acc = 1;
			while (num % cur == 0) { num /= cur; acc *= cur; }
			fdivs[i].push_back(acc);
		}
	}

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		ll num = a[i];
		for (int j = 0; j < facs.size(); j++) {
			ll cur = facs[j];
			ll acc = 1;
			while (num % cur == 0) { num /= cur; acc *= cur; }
			fa[i].push_back(acc);
		}
	}
	if (k == 1) {
		int mn = 0;
		for (int i = 0; i < n; i++)
			if (a[i] < a[mn]) mn = i;
		printf("1\n");
		printf("%d\n", mn + 1);
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		dp[i].resize(divs.size(), ill(Maxn, 0));
		par[i].resize(divs.size());
	}
	dp[0][divs.size() - 1] = ill(0, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < divs.size(); j++) if (dp[i][j].first < Maxn) {
			if (dp[i][j] < dp[i + 1][j]) { dp[i + 1][j] = dp[i][j]; par[i + 1][j] = j; }
			ll nw = 1;
			for (int k = 0; k < facs.size(); k++)
				if (fdivs[j][k] > fa[i][k])
					nw *= (fdivs[j][k] / fa[i][k]);
			int ind = lower_bound(divs.begin(), divs.begin() + j + 1, nw) - divs.begin();
			ill cand = ill(dp[i][j].first + 1, dp[i][j].second + a[i]);
			if (cand < dp[i + 1][ind]) { dp[i + 1][ind] = cand; par[i + 1][ind] = j; }
		}
	int r = n, c = 0;
	if (dp[r][c].first >= Maxn) { printf("-1\n"); return 0; }
	while (r > 0) {
		if (par[r][c] != c) res.push_back(r);
		c = par[r][c]; r--;
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}