#include<bits/stdc++.h>
#define ll long long
using namespace std;
int nop[1000010],p[100010],cnt;
void init(int n)
{
	nop[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!nop[i]) p[++cnt]=i;
		for (int j=1;j<=cnt && i*p[j]<=n;j++)
		{
			nop[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
}
ll ans;
vector<int> a[200010];
void cal(int x)
{
	int n=a[x].size(),i;
	for (i=0;i<n;i++) if (!nop[a[x][i]])
	{
		int l=i-1,r=i+1;
		while (l>=0 && a[x][l]==1) l--;
		while (r<n && a[x][r]==1) r++;
		ans+=1ll*(i-l)*(r-i)-1;
	}
}
int main()
{
	init(1000000);
	int T;cin>>T;
	while (T--)
	{
		int n,e,t,i;cin>>n>>e;ans=0;
		for (i=0;i<=n;i++) a[i].clear();
		for (i=1;i<=n;i++)
		{
			cin>>t;a[i%e].push_back(t);
		}
		for (i=0;i<e;i++) cal(i);cout<<ans<<endl;
	}
}