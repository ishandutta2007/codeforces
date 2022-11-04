#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200005;

int a[N], f[N]; ll dis[N], pos[N], res[N];

int n; 

void add(ll *b, int x, ll v)
{
	for (int i = x; i <= n; i += i & -i)
		b[i] += v;
}

ll qry(ll *b, int x)
{
	ll ret = 0;
	for (int i = x; i > 0; i ^= i & -i)
		ret += b[i];
	return ret;	
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], f[a[i]] = i;
	ll t = 0;
	for (int i = 1; i <= n; i++)
	{
		int p = f[i];
		t += qry(pos, n) - qry(pos, p);
		add(pos, p, 1);
		add(dis, p, p);
		int j = (i + 1) / 2, l = 1, r = n;
		while (l < r)
		{
			int m = (l + r) >> 1;	
			if (qry(pos, m) >= j)
				r = m;
			else
				l = m + 1;
		}
		int x = l;
		ll r1 = j - 1, r2 = i - j, cur = t;
		if (r1 > 0)
			cur += r1 * x - qry(dis, x - 1) - r1 * (r1 + 1) / 2;
		if (r2 > 0)
			cur += (qry(dis, n) - qry(dis, x)) - r2 * x - r2 * (r2 + 1) / 2;
		res[i] = cur;
//		cout << "t: " << t << endl;
//		cout << "r1: " << r1 << " r2: " << r2 << " cur: " << cur << " x: " << x << endl;
//		system("pause");
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;	
}