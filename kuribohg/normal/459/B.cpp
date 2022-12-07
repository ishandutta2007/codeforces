#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,a[200010],s1=1,s2=1,c1,c2;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++) if(a[i]>a[s1]) s1=i;
	for(int i=2;i<=n;i++) if(a[i]<a[s2]) s2=i;
	for(int i=1;i<=n;i++) if(a[i]==a[s1]) c1++;
	for(int i=1;i<=n;i++) if(a[i]==a[s2]) c2++;
	ans=(long long)c1*c2;
	if(a[s1]==a[s2]) ans=(long long)c1*(c1-1)/2;
	printf("%d %I64d\n",a[s1]-a[s2],ans);
	return 0;
}