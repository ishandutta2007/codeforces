#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int p[10000010],pn,u[10000010],mu[10000010],phi[10000010],cnt,s[10000010];
ll ans, ans1;
int main()
{
	int n;
	n = read();
	rep(i, 2, n)
	{
		if(!u[i]) p[++ pn] = u[i] = i, mu[i] = -1, phi[i] = i - 1;
		for(int j = 1; i * p[j] <= n; j ++)
		{
			u[i * p[j]] = p[j];
			if(i % p[j]) mu[i * p[j]] = -mu[i], phi[i * p[j]] = phi[i] * (p[j] - 1);
			else{phi[i * p[j]] = phi[i] * p[j]; break;}
		}
		s[u[i]] ++;
		ans += i - 1 - phi[i];
	}
	rep(i, 1, pn)
		if(p[i] > n / 2)
			cnt ++;
	ans += 3 * (1ll * (n - 1) * (n - 2) / 2 - ans - 1ll * cnt * (n - 1 - cnt) - 1ll * cnt * (cnt - 1) / 2);
	rep(i, 2, n) s[i] += s[i - 1];
	rep(i, 2, n) ans1 += 1LL * (s[i] - s[i - 1]) * s[n / i];
	rep(i, 2, n) ans1 += (1LL * (n / i) * (n / i) - (1LL * i * i > n && u[i] == i)) * mu[i];
	printf("%I64d", ans - ans1 / 2);
	return 0;
}