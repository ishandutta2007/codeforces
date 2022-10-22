#include<bits/stdc++.h>
#define Deg fprintf(stderr,"Passing [%s] line %d\n",__FUNCTION__,__LINE__)
using namespace std;
const int maxn=310000;
int n;
int a[maxn];
int to[maxn];
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) a[i+2*n]=a[i+n]=a[i];
	int mx=a[1],mn=a[1];
	for(int i=2;i<=n;i++) 
	{
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(mx<=mn*2) 
	{
		for(int i=1;i<=n;i++) printf("-1 ");
		printf("\n");
		return 0;
	}
	deque<int> q;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		while(!q.empty()&&q.front()<i) q.pop_front();
		while((q.empty()||(!q.empty()&&a[q.front()]<=a[tot+1]*2))&&tot<3*n)
		{
			tot++;
			while(!q.empty()&&a[q.back()]<=a[tot]) q.pop_back();
			q.push_back(tot);
		}
		to[i]=tot-i+1;
	}
	for(int i=1;i<=n;i++) printf("%d ",to[i]);
	printf("\n");
	return 0;
}