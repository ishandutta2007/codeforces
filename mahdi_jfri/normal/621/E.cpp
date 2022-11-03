#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 5e4 + 20;
const int maxm = 1e2 + 20;
const int mod = 1e9 + 7;

struct matrix
{
	int val[maxm][maxm];
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

int a[maxn];

int main()
{
	int n , b , k , x;
	cin >> n >> b >> k >> x;
	matrix A(x);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < x; i++)
		for(int j = 0; j < n; j++)
			A[i][(i * 10 + a[j]) % x]++;
	A = A ^ b;
	cout << A[0][k] << endl;
}