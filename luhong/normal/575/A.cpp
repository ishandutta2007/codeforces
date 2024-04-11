#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#define MN 50100

typedef long long ll;

ll k; int n; 
std::map<ll, int> mp;
int mod, s[MN];
struct xxx {
	int a[2][2];
	xxx(){}
	xxx(int A, int B, int C, int D) 
	{
		a[0][0] = A; a[0][1] = B;
		a[1][0] = C; a[1][1] = D;
	}
}p[MN], P, st[MN][20];

ll q[MN];

xxx operator * (xxx a, xxx b)
{
	xxx c; memset(c.a, 0, sizeof(c.a));
	for(int i = 0; i < 2; i++)
		for(int k = 0; k < 2; k++)
			if(a.a[i][k])
				for(int j = 0; j < 2; j++)
					c.a[i][j] = (c.a[i][j] + 1ll * a.a[i][k] * b.a[k][j]) % mod;
	return c;
}

xxx get(ll l, ll r)
{
	l %= n; r %= n;
	xxx ans = xxx(1, 0, 0, 1);
	int len = r - l + 1; 
	for(int i = 0; i <= 17; i++)
		if((len >> i) & 1) ans = ans * st[l][i], l += 1 << i;
	return ans;
}

xxx qpow(xxx x, ll p)
{
	xxx ans = xxx(1, 0, 0, 1);
	while(p)
	{
		if(p & 1) ans = ans * x;
		x = x * x; p >>= 1;
	}
	return ans;
}

xxx solve(ll l, ll r)
{
	xxx ans = xxx(1, 0, 0, 1);
	if(l > r) return ans;
	ll lb = l / n, rb = r / n; 
	if(lb == rb) return get(l, r);
	ans = ans * get(l, (lb + 1) * n - 1);
	ans = ans * qpow(P, rb - lb - 1);
	ans = ans * get(rb * n, r);
	return ans;
}

int w(ll x)
{
	if(mp.find(x) != mp.end()) return mp[x];
	else return s[x % n];
}

int main()
{
	scanf("%lld%d", &k, &mod);
	if(k == 0) return 0 * puts("0");
	if(k == 1) return 0 * printf("%d\n", 1 % mod);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &s[i]);
	P = xxx(1, 0, 0, 1);
	for(int i = 0; i < n; i++)
		st[i][0] = xxx(s[(i + 1) % n], 1, s[i], 0), P = P * st[i][0];
	for(int i = 1; i <= 17; i++)
		for(int j = 0; j + (1 << i) - 1 < n; j++)
			st[j][i] = st[j][i - 1] * st[j + (1 << (i - 1))][i - 1];
	xxx ans = xxx(1, 0, 0, 0);
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int v;
		scanf("%lld%d", &q[i], &v);
		mp[q[i]] = v;
	}
	if(mp.find(k - 1) == mp.end())
	{
		mp[k - 1] = s[(k - 1) % n];
		++m; q[m] = k - 1;
	}
	std::sort(q + 1, q + m + 1);
	ll lst = 0;
	for(int i = 1; i <= m; i++)
	{
		ans = ans * solve(lst, q[i] - 2);
		if(q[i] > lst) ans = ans * xxx(w(q[i]), 1, w(q[i] - 1), 0);
		if(q[i] == k) break;
		ans = ans * xxx(w(q[i] + 1), 1, w(q[i]), 0);
		lst = q[i] + 1;
		if(lst == k) break;
	}
	printf("%d\n", ans.a[0][1]);
}