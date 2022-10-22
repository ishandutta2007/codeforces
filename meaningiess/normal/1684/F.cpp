#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int a[N],b[N],d[N],f[N];vector<int> e[N];
pair<int,int> c[N];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;cin>>n>>m;
		for (i=0;i<=n;i++) e[i].clear(),f[i]=d[i]=0;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		int k=unique(b+1,b+n+1)-b-1;
		for (i=1;i<=n;i++)
		{
			a[i]=lower_bound(b+1,b+k+1,a[i])-b;
			e[a[i]].push_back(i);
		}
		for (i=1;i<=m;i++)
		{
			cin>>c[i].first>>c[i].second;
			d[c[i].first]=max(d[c[i].first],c[i].second);
		}
		for (i=1;i<=n;i++) d[i]=max(d[i],d[i-1]);
		int ans=n,l1=n+1,r1=0;
		for (i=1;i<=k;i++)
		{
			int flg=0,l=-1,r;
			//cout<<e[i].size()<<endl;
			for (int j=0;j<e[i].size()-1;j++)
			{
				int tp=d[e[i][j]];
				if (tp>=e[i][j+1])
				{
					if (l==-1) l=j+1;
					r=j;
				}
			}
			//cout<<e[i][l]<<' '<<e[i][r]<<endl;
			if (l!=-1)
			{
				l1=min(l1,e[i][l]);r1=max(r1,e[i][r]);
				if (d[e[i][l-1]]>=e[i][r+1]) f[e[i][l-1]+1]=e[i][r+1];
			}
		}
		for (i=1;i<=n;i++) f[i]=max(f[i-1],f[i]);
		for (i=1;i<=l1;i++) ans=min(ans,max(r1,f[i])-i+1);
		cout<<max(0,ans)<<endl;
	}
}