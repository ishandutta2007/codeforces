#include<bits/stdc++.h>
#define sit set<int>::iterator
using namespace std;
const int maxn=200000;
const int inf=1000000000;
int n,k;
int a[maxn+5],v[maxn+5],sz=0;
int st[maxn+5],top;
int chk()
{
	int tot=k;
	for(int i=1;i<=n;i++) if(!v[i]) a[++tot]=i;
	top=0;
	memset(v,0,(n+5)*sizeof(int));
	tot=0;
	for(int i=1;i<=n;i++)
	{
		while(!v[i]) st[++top]=a[++tot],v[a[tot]]=1;
		if(st[top]^i) return 0;
		top--;
	}
	return 1;
		
}
void solve()
{
	set<int> s;
	for(int i=1;i<=n;i++) s.insert(i);
	for(int i=1;i<=k;i++) s.erase(a[i]);
	top=0;
	st[++top]=inf;
	int tot=1;
	for(int i=1;i<=k;i++)
	{
		st[++top]=a[i];
		while(st[top]==tot) tot++,top--;
	}
	for(int i=k+1;i<=n;i++)
	{
		sit it=s.lower_bound(st[top]);
		if(it==s.begin())
		{
			while(st[top]==tot) top--,tot++;
			it=s.lower_bound(st[top]);
		}
		it--;
		a[i]=*it,st[++top]=a[i];
		
		s.erase(it);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		v[a[i]]=1;
		sz=max(sz,a[i]);
	}
	if(!chk()) 
	{
		printf("-1\n");
		return 0;
	}
	solve();
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}