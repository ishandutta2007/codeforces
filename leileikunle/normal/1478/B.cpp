#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int size = 1e5+10;
signed main()
{
	ios;
	int tt; cin>>tt; 
	while(tt--)
	{
		int q,d; cin>>q>>d;
		for(int i=1;i<=q;i++)
		{
			int flag = 0;
			int t; cin>>t;
			if(t>=d*10 || t%d==0)
			{
				cout<<"YES"<<endl;
				continue;
			}
			for(int i=1;i<=t/d;i++)
			{
				if((t-d*i)%10==0)
				{
					 flag = 1;
					 break;
				}
			}
			cout<<(flag?"YES":"NO")<<endl;
		}
	}
 }