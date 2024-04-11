#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,k,i;cin>>n>>k;
		if (k==0)
		{
			for (i=0;i<n/2;i++) cout<<i<<' '<<n-i-1<<endl;
			continue;
		}
		if (n<=4 && k==n-1) {puts("-1");continue;}
		else if (k==n-1)
		{
			cout<<n-1<<' '<<n-2<<endl;
			for (i=3;i<n/2;i++) cout<<i<<' '<<n-i-1<<endl;
			cout<<1<<' '<<n-3<<endl<<2<<' '<<0<<endl;
			continue;
		}
		for (i=1;i<n/2;i++) if (i!=k && i!=n-k-1)
		{
			cout<<i<<' '<<n-i-1<<endl;
		}
		cout<<0<<' '<<n-k-1<<endl<<k<<' '<<n-1<<endl;
	}
}