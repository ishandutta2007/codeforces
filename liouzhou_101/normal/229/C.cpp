#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1000010;

long long n,m,ans,tmp;
long long d[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		++d[x];
		++d[y];
	}
	ans=n*(n-1)*(n-2)/6;
	for (int i=1;i<=n;++i)
		tmp+=d[i]*(n-d[i]-1);
	cout<<ans-tmp/2<<endl;
	return 0;
}