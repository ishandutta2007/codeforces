#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
const int inf=1e8;
int n;
int a[maxn+5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int mn=a[1];
	for(int i=2;i<=n;i++) mn=min(mn,a[i]);
	int las=-inf,ans=n+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]^mn) continue;
		ans=min(ans,i-las);
		las=i;
	}
	printf("%d\n",ans);
	return 0;
}