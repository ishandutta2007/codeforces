#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define int ll

const int maxn = 5e3 + 20;
const int mod = 1e9 + 7;

int cn[maxn] , t[maxn][maxn];

void ok(int &a)
{
	a %= mod;
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int pw(int a , int b)
{
	if(!b)
		return 1;
	int x = pw(a , b / 2);
	x = (1LL * x * x) % mod;

	if(b & 1)
		x = (1LL * x * a) % mod;

	return x;
}

int cal(int r , int s)
{
	if(r > s)
		return 0;
	vector<int> x;
	for(int i = 1; i <= r; i++)
		x.pb(i);

	int res = 1;
	for(int i = s; i > s - r; i--)
	{
		int tmp = i;
		for(int i = 0; i < r; i++)
		{
			int g = __gcd(x[i] , tmp);
			x[i] /= g;
			tmp /= g;
		}
		res = 1LL * res * tmp % mod;
	}
	return res;
}

int32_t main()
{
	int n , k;
	cin >> n >> k;

	cn[k] = cal(k , n);
	for(int i = k - 1; i >= 0; i--)
		cn[i] = (cn[i + 1] * (i + 1) % mod) * pw(n - i , mod - 2) % mod;

	if(n < k)
	{
		for(int i = 0; i < maxn; i++)
			for(int j = 0; j <= i; j++)
			{
				if(!j || i == j)
					t[i][j] = 1;
				else
					ok(t[i][j] = t[i - 1][j] + t[i - 1][j - 1]);
			}
		int res = 0;
		for(int i = 1; i <= n; i++)
			ok(res += t[n][i] * pw(i , k) % mod);

		cout << res << endl;
		return 0;
	}

	int res = 0;

	t[1][1] = 1;

	for(int i = 2; i <= k; i++)
		for(int j = 1; j <= i; j++)
			t[i][j] = (j * t[i - 1][j - 1] + j * t[i - 1][j]) % mod;

	for(int i = 1; i <= k; i++)
		ok(res += (cn[i] * t[k][i] % mod) * pw(2 , n - i) % mod);

	cout << res << endl;

}