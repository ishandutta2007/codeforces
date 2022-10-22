#include <bits/stdc++.h>
using namespace std;
#define N 100005 
int n,tp,ans,nw1,nw2,a[N],nxt[N];
struct Node {int x,vl;}b[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1]) b[++tp]=(Node) {a[i],0};++b[tp].vl;
	}nxt[tp+1]=tp+1;
	for(int i=tp;i;--i)
	{if(b[i].vl>1) nxt[i]=i;else nxt[i]=nxt[i+1];}
	for(int i=1;i<=tp;++i)
	{
		if(b[i].vl>1)
		{
			if(nw1!=b[i].x) ++ans;if(nw2!=b[i].x) ++ans;
			nw1=nw2=b[i].x;
		}
		else
		{
			if(b[i].x==b[nxt[i]].x)
			{
				if(nw1!=b[i].x) ++ans,nw1=b[i].x;
				else if(nw2!=b[i].x) ++ans,nw2=b[i].x;
			}
			else
			{
				if(nw1==b[nxt[i]].x) ++ans,nw1=b[i].x;
				else if(nw2==b[nxt[i]].x) ++ans,nw2=b[i].x;
				else if(nw1!=b[i].x) ++ans,nw1=b[i].x;
				else if(nw2!=b[i].x) ++ans,nw2=b[i].x;
			}
		}
	}printf("%d\n",ans);return 0;
}