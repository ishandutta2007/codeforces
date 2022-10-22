#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[300005],ans,l,b[300005],r;
bool Cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>k;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=k;i++) cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+k+1,Cmp);
		ans=0;
		l=1;r=n;
		for (int i=1;i<=k;i++) if (b[i]==1) ans+=a[r]*2,r--;
		for (int i=1;i<=k;i++)
		{
			if (b[i]==1) break;
			ans+=a[l]+a[r];
			r--,l+=b[i]-1;
		}
		cout<<ans<<endl;
	}
}