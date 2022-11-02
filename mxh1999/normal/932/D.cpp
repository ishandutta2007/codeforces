#include<bits/stdc++.h>
using namespace std;

const int maxn=400010;
typedef long long ll;
int Q,n;
ll a[maxn];
int fa[maxn][20];
ll sum[maxn][20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>Q;
	n=1;
	ll last=0;
	while (Q--)
	{
		int op;
		ll x,y;
		cin>>op>>x>>y;
		x^=last;
		y^=last;
		if (op==1)
		{
			int now=x;
			n++;
			a[n]=y;
			if (a[x]>=y)
			{
				fa[n][0]=x;
			}	else
			{
				int tmp=0;
				for (int i=19;i>=0;i--)
				if (fa[now][i]!=0)
				{
					if (a[fa[now][i]]>=y)	tmp=fa[now][i];else now=fa[now][i];
				}
				fa[n][0]=tmp;
			}
			sum[n][0]=y;
			for (int i=0;fa[fa[n][i]][i];i++)
			{
				fa[n][i+1]=fa[fa[n][i]][i];
				sum[n][i+1]=sum[n][i]+sum[fa[n][i]][i];
			}
		}	else
		{
			int now=x;
			int ans=0;
			for (int i=19;i>=0;i--)
			if (fa[now][i]!=0)
			{
				if (sum[now][i]<=y)
				{
					y-=sum[now][i];
					ans+=1LL<<i;
					now=fa[now][i];
				}
			}
			if (a[now]<=y)	ans++;
			last=ans;
			cout<<ans<<endl;
		}
	}
	return 0;
}