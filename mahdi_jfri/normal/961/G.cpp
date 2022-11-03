#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int mod = 1e9 + 7;

int fac[maxn] , caf[maxn];

void mkay(int &a)
{
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

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

int c(int r , int s)
{
	if(r < 0 || r > s)
		return 0;

	return 1LL * fac[s] * caf[r] % mod * caf[s - r] % mod;
}

int get(int n , int k)
{
	if(k > n)
		return 0;

	int res = 0;
	for(int i = k; i >= 1; i--)
	{
		if((k - i) % 2)
			mkay(res -= 1LL * pw(i , n) * c(i , k) % mod);
		else
			mkay(res += 1LL * pw(i , n) * c(i , k) % mod);
	}

	return (1LL * res * caf[k] % mod);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxn - 1] = pw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int n , k;
	cin >> n >> k;

	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		mkay(sum += x);
	}

	int res = 1LL * sum * get(n , k) % mod;
	mkay(res += 1LL * (n - 1) * sum % mod * get(n - 1 , k) % mod);
	cout << res << endl;
}