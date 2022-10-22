#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,nw,l,r,ans[N];bool vs[N];char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %s",&n,a+1);
		for(int i=1;i<=n;++i) vs[i]=ans[i]=0;
		for(int i=1;i<=n;)
		{
			l=r=i;while(r<n && a[r]=='<') ++r;
			if(a[i]=='<') for(int j=l;j<=r;++j)
				vs[ans[j]=n-l-r+j+1]=1;i=r+1;
		}nw=n;
		for(int i=1;i<=n;++i)
		{
			while(vs[nw]) --nw;if(!ans[i]) ans[i]=nw--;
			printf("%d ",ans[i]);
		}puts("");
		for(int i=1;i<=n;++i) vs[i]=ans[i]=0;
		for(int i=1;i<=n;)
		{
			l=r=i;while(r<n && a[r]=='>') ++r;
			if(a[i]=='>') for(int j=l;j<=r;++j)
				vs[ans[j]=l+r-j]=1;i=r+1;
		}nw=1;
		for(int i=1;i<=n;++i)
		{
			while(vs[nw]) ++nw;if(!ans[i]) ans[i]=nw++;
			printf("%d ",ans[i]);
		}puts("");
	}return 0;
}