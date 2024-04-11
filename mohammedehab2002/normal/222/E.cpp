#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
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
	long long n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	matrix mat(m,vector<long long>(m,1));
	while (k--)
	{
		char a,b;
		getchar();
		a=getchar();
		b=getchar();
		if (a>='a')
		a-='a';
		else
		a=a-'A'+26;
		if (b>='a')
		b-='a';
		else
		b=b-'A'+26;
		mat[a][b]=0;
	}
	if (n==1)
	{
		printf("%d",m);
		return 0;
	}
	matrix tmp=pow(mat,n-1);
	matrix vec(m,vector<long long>(m,0));
	for (int i=0;i<m;i++)
	vec[i][0]=1;
	vec=mul(tmp,vec);
	long long ans=0;
	for (int i=0;i<m;i++)
	ans=(ans+vec[i][0])%mod;
	printf("%I64d",ans);
}