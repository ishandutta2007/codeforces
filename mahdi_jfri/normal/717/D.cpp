#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ld double
const int maxn = 2e2 + 20;

struct matrix
{
	ld val[maxn][maxn];
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
	ld* operator[] (int x)
	{
		return val[x];
	}
	matrix operator * (matrix b)
	{
		matrix ans(n, 0);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++)
					ans[i][k] += val[i][j] * b[j][k];
		return ans;
	}
	matrix operator + (matrix b)
	{
		matrix ans(n , 0);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ans[i][j] = (val[i][j] + b[i][j]);
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

ld p[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , x;
	cin >> n >> x;
	matrix A(maxn - 1 , 0);
	for(int i = 0; i <= x; i++)
		cin >> p[i];
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			if((i ^ j) < maxn)
				A[i][j] = p[i ^ j];
	A = A ^ n;

	cout << fixed << setprecision(10) << 1 - A[0][0] << endl;
}