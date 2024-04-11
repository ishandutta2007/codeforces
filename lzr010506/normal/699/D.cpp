#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=200005;

int n,fa[N],a[N],root,q[N],ins[N],vis[N];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&fa[i]);
	for (int i=1; i<=n; i++) a[i]=fa[i];
	root=0;
	for (int i=1; i<=n; i++) if (fa[i]==i) {root=i; break;}
	for (int i=1; i<=n; i++)
	{
	  	q[0]=0;
	  	int x=i;
	  	while (1)
	  	{
	  		if (ins[x]) 
	  		{
	  			if (root==0) root=x;
	  			fa[x]=root;
	  			break;
	  		}
	  		if (vis[x]) break;
	  		q[++q[0]]=x; ins[x]=vis[x]=1;
	  		if (x==fa[x]) {fa[x]=root; break;}
	  		x=fa[x];
	  	}
	  	while (q[0]) 
	  	{
	  		ins[q[q[0]]]=0;
	  		q[0]--;
	  	}
	}
	for (int i=1; i<=n; i++) 
	  if (a[i]!=fa[i]) a[0]++;
	printf("%d\n",a[0]);
	for (int i=1; i<=n; i++) printf("%d ",fa[i]); printf("\n");
	return 0;
}