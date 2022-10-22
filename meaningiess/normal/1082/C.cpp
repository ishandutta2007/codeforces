#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long
#define N 100100
using namespace std;
ll s[N];struct fck{vector<ll> v;ll s,c;}g[N];
int main()
{
	ll ans=0,a,b,n,m,i,j;cin>>n>>m;
	for (i=1;i<=n;i++){cin>>a>>b;g[a].v.push_back(b);g[a].c++,g[a].s+=b;}
	for (i=1;i<=m;i++)
	{
		sort(g[i].v.begin(),g[i].v.end());ll lim=g[i].c,t=0;
		for (j=lim-1;j>=0;j--){t+=g[i].v[j];if (t>0) s[lim-j]+=t;else break;}
	}
	for (i=1;i<=n;i++) ans=max(ans,s[i]);cout<<ans;
}