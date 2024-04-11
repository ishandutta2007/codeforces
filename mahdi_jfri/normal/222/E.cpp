#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 60;
const ll mod = 1e9 + 7;


struct matrix
{
	int val[maxn][maxn];
	int n;
	matrix(int nn, int x = 0)
	{
		n = nn;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (i != j)
					val[i][j] = 0;
				else
					val[i][j] = x;
	}
	int* operator[] (int x)
	{
		return val[x];
	}
	matrix operator * (matrix b)
	{
		matrix ans(n, 0);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++)
					ans[i][k] += 1LL * val[i][j] * b[j][k] % mod, ans[i][k] %= mod;
		return ans;
	}
};

matrix operator ^ (matrix a, ll b)
{
	matrix ans(a.n, 1);
	while(b)
	{
		if (b & 1)
			ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int main()
{
	ll n , m , k;
	cin >> n >> m >> k;
	matrix a(m , 0);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			a[i][j] = 1;
	for(int i = 0; i < k; i++)
	{
		string x;
		cin >> x;
		if('A' <= x[0] && x[0] <= 'Z')
			x[0] = x[0] - 'A' + 'a' + 26;
		if('A' <= x[1] && x[1] <= 'Z')
			x[1] = x[1] - 'A' + 'a' + 26;
		x[0] -= 'a';
		x[1] -= 'a';
		a[(int)x[0]][(int)x[1]] = 0;
	}
	a = a ^ (n - 1);

	ll res = 0;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			res += a[i][j] , res %= mod;
	cout << res << endl;
}