#include <iostream>
#include <vector>
using namespace std;
#define m 1000000000000000000
typedef vector<vector<long long> > matrix;
matrix mul(matrix a,matrix b)
{
	matrix c(a.size(),vector<long long>(b[0].size(),0));
	for (int i=0;i<a.size();i++)
	{
		for (int x=0;x<b[0].size();x++)
		{
			for (int j=0;j<b.size();j++)
			{
			    if (!b[j][x])
			    continue;
			    if (a[i][j]>=2LL*m/b[j][x])
			    c[i][x]=m;
			    else
			    c[i][x]=min(c[i][x]+a[i][j]*b[j][x],m);
			}
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
matrix mat,con;
long long arr[200005];
int main()
{
	int n;
	long long k;
	scanf("%d%I64d",&n,&k);
	bool b=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i]>=k)
		{
			printf("0");
			return 0;
		}
		if (arr[i])
		b=1;
		if (!b && !arr[i])
		{
			i--;
			n--;
			continue;
		}
		mat.push_back({arr[i]});
	}
	if (n>5)
	{
		int ans=0;
		while (1)
		{
			ans++;
			for (int i=1;i<n;i++)
			{
				arr[i]+=arr[i-1];
				if (arr[i]>=k)
				{
					printf("%d",ans);
					return 0;
				}
			}
		}
	}
	vector<long long> tmp(n,0);
	for (int i=0;i<n;i++)
	{
		tmp[i]=1;
		con.push_back(tmp);
	}
	long long st=1,en=m+5;
	while (st!=en)
	{
		long long mid=(st+en)/2;
		matrix t=pow(con,mid);
		t=mul(t,mat);
		if (t[n-1][0]>=k)
		en=mid;
		else
		st=mid+1;
	}
	printf("%I64d",st);
}