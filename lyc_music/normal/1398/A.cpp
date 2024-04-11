#include<bits/stdc++.h>
#define int long long
#define N 500005
//#define inf 
//#define mod 
int T,n,a[N],bl;
using namespace std;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;bl=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i+2<=n;i++)
		  if (!(a[i]+a[i+1]>a[n]&&a[i+1]-a[i]<a[n]))
		  {
		  	bl=1;
		  	cout<<i<<" "<<i+1<<" "<<n<<endl;break;
		  }
		if (!bl) cout<<-1<<endl;
	}
	
}