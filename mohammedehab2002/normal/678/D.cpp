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
	long long a,b,n,x;
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&x);
	matrix mat,vec;
	mat.push_back({a,1});
	mat.push_back({0,1});
	vec.push_back({x});
	vec.push_back({b});
	vec=mul(pow(mat,n),vec);
	printf("%I64d",vec[0][0]);
}