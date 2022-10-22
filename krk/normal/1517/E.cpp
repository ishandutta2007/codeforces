#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 400005;
const int mod = 998244353;

int T;
int n;
int a[Maxn];
ll sum[Maxn];
ll pc[Maxn];
vector <ll> un;
int BIT[Maxn];

void addBit(int x)
{
	x++;
	for (int i = x; i > 0; i -= i & -i)
		BIT[i]++;
}

int getBit(int x)
{
	int res = 0;
	x++;
	for (int i = x; i <= un.size(); i += i & -i)
		res += BIT[i];
	return res;
}

int Add(int od)
{
	un.clear();
	for (int i = 1; i < n; i++)
		if ((i + 1) % 2 == od)
			un.push_back(-sum[i] + pc[i + 1]);
		else un.push_back(sum[1] - (sum[i + 1] - sum[1]) + pc[i + 2]);
	sort(un.begin(), un.end());
	un.erase(unique(un.begin(), un.end()), un.end());
	fill(BIT, BIT + int(un.size()) + 1, 0);
	int res = 0;
	for (int i = od == 1? 1: 2; i <= n; i += 2) {
		if (i - 1 >= 1) {
			int ind = lower_bound(un.begin(), un.end(), -sum[i - 1] + pc[i]) - un.begin();
			addBit(ind);
		}
		if (i - 2 >= 1) {
			int ind = lower_bound(un.begin(), un.end(), sum[1] - (sum[i - 1] - sum[1]) + pc[i]) - un.begin();
			addBit(ind);
		}
		ll my = -pc[i] + (sum[n] - sum[i - 1]);
		ll nd = upper_bound(un.begin(), un.end(), -my) - un.begin();
		res = (res + getBit(nd)) % mod;
		if (i < n) {
			my = -pc[i] + (sum[n - 1] - sum[i - 1]) - (sum[n] - sum[n - 1]);
			nd = upper_bound(un.begin(), un.end(), -my) - un.begin();
			res = (res + getBit(nd)) % mod;
		}
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		pc[n + 1] = 0;
		for (int i = n; i > 0; i--)
			pc[i] = a[i] - pc[i + 1];
		un.clear();
		int res = 1;
		for (int i = 1; i < n; i++)
			if (sum[i] > sum[n] - sum[i])
				res++;
		res = (res + Add(0)) % mod;
		res = (res + Add(1)) % mod;
		printf("%d\n", res);
	}
    return 0;
}