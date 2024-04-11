#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[10],b[10],c[10],ans,t;
signed main()
{
	cin>>T;
	while (T--)
	{
		n=3;ans=0;
		for (int i=0;i<=2;i++) cin>>a[i];
		for (int i=0;i<=2;i++) cin>>b[i];
		ans+=min(b[1],a[2])*2,t=min(b[1],a[2]),b[1]-=t,a[2]-=t;
		ans+=min(b[2],a[2])*0,t=min(b[2],a[2]),b[2]-=t,a[2]-=t;
		ans+=min(b[2],a[0])*0,t=min(b[2],a[0]),b[2]-=t,a[0]-=t;
		ans+=min(b[1],a[1])*0,t=min(b[1],a[1]),b[1]-=t,a[1]-=t;
		ans+=min(b[1],a[0])*0,t=min(b[1],a[0]),b[1]-=t,a[0]-=t;
		ans+=min(b[0],a[1])*0,t=min(b[0],a[1]),b[0]-=t,a[1]-=t;
		ans+=min(a[1],b[2])*-2,t=min(a[1],b[2]),a[1]-=t,b[2]-=t;
		cout<<ans<<endl;
	}
}