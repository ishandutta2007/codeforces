#include<iostream>
#include<cstring>
#include<cstdio>
#define N 500010
using namespace std;
int f[N],l[N],a[N],s[N];
int main()
{
	int n,c,i,nw=0,ans=0;scanf("%d%d",&n,&c);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+(int)(a[i]==c);
	for (i=1;i<=n;i++) f[i]=max(max(f[l[a[i]]]+1,s[i-1]+1),s[l[a[i]]-1]+1+(int)(l[a[i]]!=0)),l[a[i]]=i;
	for (i=n;i;i--) ans=max(ans,f[i]+nw),nw+=(int)(a[i]==c);cout<<ans;
}