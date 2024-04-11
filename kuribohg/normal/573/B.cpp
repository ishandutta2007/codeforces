#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,h[MAXN],f[MAXN],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=1;i<=n;i++) f[i]=1000000000;
	f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=min(f[i],min(f[i-1]+1,h[i]));
	f[n]=1;
	for(int i=n-1;i>=0;i--)
		f[i]=min(f[i],min(f[i+1]+1,h[i]));
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}