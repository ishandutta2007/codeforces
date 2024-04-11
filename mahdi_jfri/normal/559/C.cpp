#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxh = 4e5 + 20;
const int maxn = 2e3 + 20;
const int mod = 1e9 + 7;

int fac[maxh] , caf[maxh] , a[maxn] , x[maxn] , y[maxn] , dp[maxn];

int c(int r , int s)
{
	if(r < 0 || r > s)
		return 0;

	int ans = 1LL * fac[s] * caf[r] % mod;
	ans = 1LL * ans * caf[s - r] % mod;

	return ans;
}

int path(int x1 , int y1 , int x2 , int y2)
{
	return c(abs(x1 - x2) , abs(x1 - x2) + abs(y1 - y2));
}

inline void mkay(int &a)
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
	if(b & 1)
		x = 1LL * x * a % mod;

	return x;
}

bool cmp(int i , int j)
{
	return make_pair(x[i] , y[i]) < make_pair(x[j] , y[j]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxh; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxh - 1] = pw(fac[maxh - 1] , mod - 2);
	for(int i = maxh - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int h , w , n;
	cin >> h >> w >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		a[i] = i;
	}

	x[n] = h;
	y[n] = w;
	a[n] = n;

	sort(a , a + n , cmp);


	for(int i = 0; i <= n; i++)
	{
		dp[i] = path(1 , 1 , x[a[i]] , y[a[i]]);

		for(int j = 0; j < i; j++)
			if(x[a[j]] <= x[a[i]] && y[a[j]] <= y[a[i]])
				mkay(dp[i] -= 1LL * dp[j] * path(x[a[j]] , y[a[j]] , x[a[i]] , y[a[i]]) % mod);
	}

	cout << dp[n] << endl;

}