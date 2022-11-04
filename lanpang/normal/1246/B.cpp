#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;
const int INF = 1e6 + 10;

vector<int> p;

int a[N], sie[N], minp[N];

int n, k;

inline ll mul(ll a, ll b)
{
	return min(a * b, (ll)INF);	
}

ll qpow(ll a, ll b)
{
	ll ret = 1;
	for (; b; a = mul(a, a), b >>= 1)
		if (b & 1)
			ret = mul(ret, a);
	return ret;
}

void init()
{
	sie[0] = 1, sie[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (!sie[i])
			p.push_back(i), minp[i] = i;
		for (auto x : p)
		{
			if (i * x > N) break;
			sie[i * x] = 1, minp[i * x] = x;
			if (i % x == 0) break;
		}
	}
}

map<int, int> dict;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);	
	init();
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		ll cur[] = {1, 1};
		int x = a[i];
		while (x > 1)
		{
			int y = minp[x], cnt = 0;
			while (x % y == 0)
				x /= y, ++cnt;
			cnt %= k;
			cur[0] = mul(cur[0], qpow(y, cnt));
			cnt = (k - cnt) % k;
			cur[1] = mul(cur[1], qpow(y, cnt));
		}
		if (cur[1] != INF)
			res += dict[cur[1]];
		dict[cur[0]] += 1;
	}
	cout << res << endl;
	return 0;	
}