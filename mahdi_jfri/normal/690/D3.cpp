#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
const ll mod = 1e6 + 3;

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
	matrix()
	{
		n = 2;
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
	matrix operator + (matrix b)
	{
		matrix ans(n , 0);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ans[i][j] = (val[i][j] + b[i][j]) % mod;
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

ll pw(ll a , ll b)
{
	if(!b)
		return 1;
	ll x = pw(a , b / 2);
	x = (x * x) % mod;
	if(b & 1)
		x = (x * a) % mod;
	return x;
}

int main()
{
	int c , w , h;
	cin >> c >> w >> h;
	matrix A(w + 1 , 0);
	for(int i = 0; i < w; i++)
		A[i][i + 1] = 1;
	
	for(int i = 0; i <= w; i++)
		A[i][0] = pw(h , i);
	A = A ^ (c + 1);
	cout << A[0][0] << endl;
}