#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1000005;

ll n;
ll res;
ll sum;
ll inum[MAXN];
bool unprime[MAXN];
int dividor[MAXN];

ll mul(ll a, ll b)
{
	return (a * b) % MOD;
}

ll bin_pow(ll a, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = mul(res, a);
		a = mul(a, a);
		n /= 2;
	}
	return res;
}

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll dif(ll a, ll b)
{
	return (a - b + MOD) % MOD;
}

ll inv(ll a)
{
	return bin_pow(a, MOD - 2);
}

/*ll c(int n, int k)
{
	return mul(fact[n], mul(ifact[n - k], ifact[k]));
}*/



int main()
{
	/*fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = mul(fact[i - 1], (ll)i);
	for (int i = 0; i < MAXN; i++)
		ifact[i] = inv(fact[i]);*/

	inum[1] = 1;
	for (int i = 2; i < MAXN; ++i)
		if (!unprime[i]) {
			for (ll j = (ll)(i) * (ll)(i); j < MAXN; j += i)
				if (!unprime[j]) {
					unprime[j] = true;
					dividor[j] = i;
				}
			inum[i] = inv(i);
		}
		else
			inum[i] = mul(inum[dividor[i]], inum[i / dividor[i]]);


	cin >> n;
	res = bin_pow(2, n) - 1;
	sum = bin_pow(2, n);
	ll cur = 1;

	for (int i = 0; i < n + 1; i++)
	{
		res = add(res, sum);
		sum = mul(dif(sum, cur), 2);
		cur = mul(cur, n + i + 1);
		cur = mul(cur, inum[i + 1]);
	}

//	cout  << sum << '\n';
	cout << res;
	return 0;
}