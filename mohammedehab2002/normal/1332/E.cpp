#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
typedef vector<vector<long long> > matrix;
matrix mul(matrix a,matrix b)
{
	matrix c(a.size(),vector<long long>(b[0].size(),0));
	for (int i=0;i<a.size();i++)
	{
		for (int x=0;x<b[0].size();x++)
		{
			for (int j=0;j<b.size();j++)
			c[i][x]=(c[i][x]+a[i][j]*b[j][x])%mod;
		}
	}
	return c;
}
matrix pow(matrix a,long long x)
{
	if (x==1)
	return a;
	matrix tmp=pow(a,x/2);
	tmp=mul(tmp,tmp);
	if (x%2)
	tmp=mul(tmp,a);
	return tmp;
}
int main()
{
	long long n,m,l,r;
	cin >> n >> m >> l >> r;
	long long e=r/2-(l-1)/2,o=(r+1)/2-l/2;
	matrix mat({{e,o},{o,e}});
	mat=pow(mat,n*m);
	cout << (mat[0][0]+(n*m%2)*mat[0][1])%mod;
}