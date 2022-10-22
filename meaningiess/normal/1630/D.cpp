#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000010],b[1000010],c[1000010];
int main()
{ios::sync_with_stdio(false);cout.tie(NULL);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,x;ll s=0,res,ans;cin>>n>>m;
		for (i=0;i<=n;i++) b[i]=1e9+1,c[i]=0;
		for (i=1;i<=n;i++) {cin>>a[i];s+=abs(a[i]);}
		cin>>x;
		for (i=2;i<=m;i++)
		{
			int u;cin>>u;x=__gcd(x,u);
		}
		for (i=1;i<=n;i++)
		{
			b[i%x]=min(b[i%x],abs(a[i]));
			if (a[i]<0) c[i%x]^=1;
		}
		res=s;
		for (i=0;i<x;i++) if (b[i]!=0 && c[i]) res-=2*b[i];
		ans=res;res=s;
		for (i=0;i<x;i++) if (b[i]!=0 && !c[i]) res-=2*b[i];
		cout<<max(ans,res)<<endl;
	}
}