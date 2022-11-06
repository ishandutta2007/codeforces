#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int a[101000];bool used[101000],u[101000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		if(!used[a[i]])u[i]=1,used[a[i]]=1;
	}int ans=0;
	for(int i=1;i<=n;i++)if(u[i])ans++;cout<<ans<<endl;
	for(int i=1;i<=n;i++)if(u[i])cout<<a[i]<<" ";
	return 0;
}