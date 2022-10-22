#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (1)
	{
		int p=1,i;cin>>s;
		if (s=="end") break;
		for (i=1;i<=30;i++)
		{
			cout<<"? "<<p<<' '<<2*p<<endl;fflush(stdout);
			char c;cin>>c;if (c=='x') break;p*=2;
		}
		int l=p,r=2*p,mid,ans=-1;
		while (l<=r)
		{
			mid=(l+r)>>1;cout<<"? "<<mid<<' '<<2*p<<endl;fflush(stdout);
			char c;cin>>c;if (c=='x') l=mid+1;else r=mid-1,ans=mid;
		}
		if (ans!=-1)cout<<"! "<<ans<<endl;
		else
		{
			cout<<"? "<<2*p<<' '<<p<<endl;fflush(stdout);
			char c;cin>>c;if (c=='x') cout<<"! "<<p<<endl;else cout<<"! "<<2*p<<endl;
		}
	}
}