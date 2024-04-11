#include<bits/stdc++.h>
#define int long long
#define N 100005
#define mo 1000000007
using namespace std;
int cnt,head[N],size[N],ans,n,m,mx,T,x,y,tp,a[N];
priority_queue <int,vector<int>,less<int> >q;
struct
{
	int to,nx;
}e[N<<1];
void ad(int x,int y)
{
	cnt++;
	e[cnt].to=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}
void dfs(int k,int fa) 
{
	size[k]=1;
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa)
	  dfs(e[i].to,k),size[k]+=size[e[i].to];
}
void dfs1(int k,int fa)
{
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa)
	  {
	  	q.push(size[e[i].to]*(n-size[e[i].to]));
	  	dfs1(e[i].to,k);
	  }
}
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;cnt=ans=mx=0;
		for (int i=1;i<=n;i++) head[i]=0;
		for (int i=1;i<n;i++)
		{
			cin>>x>>y;
			ad(x,y);
			ad(y,x);
		}
		dfs(1,0);
		dfs1(1,0);
		cin>>m;
		for (int i=1;i<=m;i++) 
		{
			cin>>a[i];
		}
		sort(a+1,a+m+1);
		n--;
		if (m>n) 
		{
		    for (int i=n+1;i<=m;i++) (a[n]*=a[i])%=mo;
		    m=n;
		}
		while (!q.empty())
		{
			tp=q.top();q.pop();
			(ans+=max(1ll,a[m--])*tp%mo)%=mo;
			if (m<0) m=0;
		}
		cout<<ans<<endl;
	}
}