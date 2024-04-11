#include <bits/stdc++.h>
#define fst first
#define sec second
#define ll long long
#define pii pair<ll, ll>
using namespace std;
pii num2(ll a)
{
	int ret = 0;
	while(1)
	{
		if (a % 2 != 0)return make_pair(ret, a);
		a /= 2;
		ret++;
	}
}
ll mat[131][131], rev[200], now[131], rt[131][131];
int main()
{
	ll num, P, Q;
	scanf("%I64d%I64d%I64d", &num, &P, &Q);
	P = min(P, num - 1);
	for (int i = 1; i < 200; i ++)
		if (i % 2 != 0)
			for (ll j = 0;; j ++)
				if (((1LL << 32) * j + 1) % i == 0)
				{
					rev[i] = ((1LL << 32) * j + 1) / i;
					break;
				}
	
	for (int i = 0; i <= P; i ++)
		for (int j = i; j <= P; j ++)
		{
			ll n = num - i;
			ll p = j - i;
			int c = 0;
			ll now = 1;
			for (int k = 1; k <= p; k ++)
			{
				pii z1 = num2(n - k + 1);
				pii z2 = num2(k);
				c += z1.fst - z2.fst;
				now *= z1.sec*rev[z2.sec] & ((1LL << 32) - 1);
				now &= ((1LL << 32) - 1);
			}
			mat[i][j] = now << (c % 32);
		}
	fill(now, now + 131, 1);
	for (int i = 0; i <= P; i++)
	{
		int n[131];
		fill(n, n + 131, 0);
		for (int j = 0; j <= P; j ++)
			for (int k = 0; k <= P; k ++)
			{
				n[j] += mat[j][k] * now[k];
				n[j] &= ((1LL << 32) - 1);
			}
		rt[0][i] = now[0];
		for (int j = 0; j <= P; j++)now[j] = n[j];
	}
	for (int i = 0; i < P; i++)
		for (int j = 0; j < P - i; j++)
			rt[i + 1][j] = (rt[i][j + 1] - rt[i][j] + (1LL << 32)) & ((1LL << 32) - 1);
	ll t = rt[P][0];
	ll ans[131];
	for (int i = 0; i <= P; i++) ans[i] = rt[i][0];
	ll ret = 0;
	for (int i = 1; i <= Q; i++)
	{
		ll n[131];
		fill(n, n + 131, 0);
		n[P] = t;
		for (int j = P - 1; j >= 0; j --)
			n[j] = (ans[j + 1] + ans[j])&((1LL << 32) - 1);
		for (int j = 0; j <= P; j++)ans[j] = n[j];
		ret ^= (ans[0] * i)&((1LL << 32) - 1);
	}
	printf("%I64d\n", ret);
}