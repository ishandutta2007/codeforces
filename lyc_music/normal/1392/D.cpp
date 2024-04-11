#include<bits/stdc++.h>
using namespace std;
int T,n,ans,len,s,j;
string st;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;
		cin>>st;st=st+st;ans=0;j=0;
		s=-1;
		for (int i=0;i<n-1;i++) if (st[i]!=st[i+1]) s=i+1;
		if (s==-1) cout<<(n+2)/3<<endl; else
		{
			for (int i=s;j<=n;i++)
			{j+=1;
			  if (st[i]==st[i-1]) len++; else ans+=len/3,len=1;
			 // cout<<st[i]<<" "<<len;
			}
			ans+=len/3;
			cout<<ans<<endl;
		}
	}
}