#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 300005;
const int Maxb = 62;

int n;
vector <lli> bybit[Maxb];
ll mask;

int main()
{
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int v; ll m; scanf("%d %I64d", &v, &m);
		int b = 0;
		while (!(m & 1ll << ll(b))) b++;
		bybit[b].push_back(lli(m, v));
		sum += v;
	}
	if (sum > 0)
		for (int i = 0; i < Maxb; i++)
			for (int j = 0; j < bybit[i].size(); j++)
				bybit[i][j].second = -bybit[i][j].second;
	for (int b = Maxb - 1; b >= 0; b--) {
		ll cur = 0;
		for (int i = 0; i < bybit[b].size(); i++)
			if (__builtin_popcountll(bybit[b][i].first & mask) % 2)
				cur -= bybit[b][i].second;
			else cur += bybit[b][i].second;
		if (cur < 0) mask |= 1ll << ll(b);
	}
	cout << mask << endl;
    return 0;
}