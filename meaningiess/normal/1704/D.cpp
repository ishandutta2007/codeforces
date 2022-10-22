#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s1[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,cnt=0,p;cin>>n>>m;
		for (i=1;i<=n;i++)
		{
			ll s2=0;s1[i]=0;
			for (int j=0;j<m;j++)
			{
				ll x;cin>>x;s2+=x;s1[i]+=s2;
			}
			if (s1[i]!=s1[1]) p=i,cnt++;
		}
		if (cnt==1) cout<<p<<' '<<s1[1]-s1[p]<<endl;
		else cout<<1<<' '<<s1[2]-s1[1]<<endl;
		
	}
}