#include <bits/stdc++.h>
using namespace std;
#define N 100005 
int n,tp,nw1,nw2,ans,a[N],b[N],nw[N],nxt[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1]) b[++tp]=a[i];
	}for(int i=1;i<=n;++i) nw[i]=tp+1;nxt[0]=tp+1;
	for(int i=tp;i;--i) nxt[i]=nw[b[i]],nw[b[i]]=i;
	for(int i=1;i<=tp;++i)
	{
		if(b[i]==b[nw1]) {nw1=i;continue;}
		if(b[i]==b[nw2]) {nw2=i;continue;}
		if(nxt[nw1]<nxt[nw2]) swap(nw1,nw2);
		if(nxt[i]<nxt[nw1]) nw1=i,++ans;
		else if(nxt[i]<nxt[nw2]) nw2=i,++ans;else nw1=i,++ans;
	}printf("%d\n",ans);return 0;
}