#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,a[100010],ans1,ans2,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=n;i++) if(a[i]!=a[i+1]) ans1++;
	for(int i=1;i<=n;i++) if(a[i]==1) ans2++;
	ans=ans2+(ans1>>1)-1;
	printf("%d\n",max(ans,0));
	return 0;
}