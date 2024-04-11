#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
ll l[N],r[N],h[N];int f[N];
int main()
{
	int T,i;cin>>T;
	while (T--)
	{
		int n,ans=0;cin>>n;
		for (i=2;i<=n;i++) cin>>f[i];
		for (i=1;i<=n;i++) {h[i]=0;cin>>l[i]>>r[i];}
		for (i=n;i;i--)
		{
			if (h[i]<l[i]) ans++;
			else if (h[i]<r[i]) r[i]=h[i];
			h[f[i]]+=r[i];
		}
		cout<<ans<<endl;
	}
	
}