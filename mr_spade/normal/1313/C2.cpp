#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,ans,x;
int a[N],h[N],size[N];
vector<int> st;
vector<int> e[N];
inline int back(int k)
{
	return st[(int)st.size()-k];
}
void dfs(int x)
{
	size[x]=1;
	for(int y:e[x])
		dfs(y),size[x]+=size[y];
	return;
}
void dfs2(int x,int t)
{
	if(t+a[x]*size[x]>ans)
		ans=t+a[x]*size[x],(::x)=x;
	for(int y:e[x])
		dfs2(y,t+a[x]*(size[x]-size[y]));
	return;
}
signed main()
{
	int lst;
	register int i,j;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{
		lst=0;
		while(!st.empty()&&a[back(1)]>a[i])
		{
			if(lst)
				e[back(1)].push_back(lst);
			lst=back(1),st.pop_back();
		}
		if(lst)
			e[i].push_back(lst);
		st.push_back(i);
	}
	lst=0;
	while(!st.empty())
	{
		if(lst)
			e[back(1)].push_back(lst);
		lst=back(1),st.pop_back();
	}
	dfs(lst);dfs2(lst,0);
	i=x;h[i]=a[i];
	for(j=i-1;j>=1;j--)
		h[j]=min(h[j+1],a[j]);
	for(j=i+1;j<=n;j++)
		h[j]=min(h[j-1],a[j]);
	for(i=1;i<=n;i++)
		printf("%lld ",h[i]);
	putchar('\n');
	return 0;
}