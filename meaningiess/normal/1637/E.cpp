#include<bits/stdc++.h>
#define ll long long
#define fi first
#define sc second
using namespace std;
map<int,int> mp;
map<ll,int> bn,us;
vector<int> e[300010];
int o[30011],cnt;
ll gt(int x,int y)
{
	return (x-1)*1000000000ll+(y-1);
}
ll gt2(int x,int y)
{
	return x*1000000000ll+y;
}
struct node
{
	ll a;int b,c;
	bool operator<(const node&u)const
	{
		return a<u.a;
	}
};
priority_queue<node> pq;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,x,y;ll ans=0;scanf("%d%d",&n,&m);mp.clear();bn.clear();
		for (i=1;i<=n;i++) e[i].clear();cnt=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x]++;bn[gt(x,x)]=1;
		}
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			bn[gt(x,y)]=bn[gt(y,x)]=1;
		}
		for (auto p:mp) e[p.sc].push_back(p.fi);
		for (i=1;i<=n;i++) if (e[i].size()>0) o[++cnt]=i;
		for (i=1;i<=cnt;i++)
		{
			for (j=i;j<=cnt;j++)
			{
				while (!pq.empty()) pq.pop();us.clear();
				int A=e[o[i]].size()-1,B=e[o[j]].size()-1;
				pq.push(node{e[o[i]][A]+e[o[j]][B],A,B});
				while (!pq.empty())
				{
					node nw=pq.top();pq.pop();
					if (!bn[gt(e[o[i]][nw.b],e[o[j]][nw.c])]) {ans=max(ans,nw.a*(o[i]+o[j]));break;}
					A=nw.b,B=nw.c;
					if (A && !us[gt2(A-1,B)])
					{
						us[gt2(A-1,B)]=1;
						pq.push(node{e[o[i]][A-1]+e[o[j]][B],A-1,B});
					}
					if (B && !us[gt2(A,B-1)])
					{
						us[gt2(A,B-1)]=1;
						pq.push(node{e[o[i]][A]+e[o[j]][B-1],A,B-1});
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}