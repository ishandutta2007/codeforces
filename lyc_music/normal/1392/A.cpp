#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300005],n,ans,len,T;
signed main()
{
	cin>>T;
	while (T--)
	{
	cin>>n;ans=0;
	for (int i=1;i<=n;i++)
	  cin>>a[i];
	for (int i=2;i<=n;i++)
	  if (a[i]!=a[i-1]) ans=1;
	  if (!ans) cout<<n<<endl; else cout<<1<<endl;
	}
}