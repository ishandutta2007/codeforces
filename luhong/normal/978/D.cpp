#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int b[101000],n,c[101000];
int Abs(int x)
{
	return x>0?x:-x;
}
int solve()
{
	int ans=0;
	for(int i=3;i<=n;i++)
	{
		int o=Abs((b[2]-b[1])-(b[i]-b[i-1]));
		if(o==1||o==0)ans+=o;else return 1e9;
		b[i]+=(b[2]-b[1])-(b[i]-b[i-1]);
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),c[i]=b[i];if(n==1)return 0*puts("0");
	int ans=1e9;
	for(int i=-1;i<=1;i++)
	for(int j=-1;j<=1;j++)
	{
		for(int k=1;k<=n;k++)b[k]=c[k];
		b[1]+=i;b[2]+=j;
		ans=min(ans,solve()+Abs(i)+Abs(j));
	}
	if(ans==1e9)puts("-1");else printf("%d",ans);
	return 0;
}