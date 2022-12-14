#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int a[100005],b[100005];
signed main()
{
	int tt; cin>>tt;
	while(tt--)
	{
		map<int,int> s;
		s[-1]=0; s[0]=0; s[1]=0;
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[a[i]]++;
		}
		bool flag = true;
		for(int i=1;i<=n;i++)	cin>>b[i];
		for(int i=n;i>=1;i--)
		{
			s[a[i]]--;
			if(a[i]>b[i])
			{
				if(s[-1]>0) continue;
				else{
					flag = false;
					break;
				}
			}else if(a[i]==b[i]) continue;
			else{
				if(s[1]>0) continue;
				else{
					flag = false;
					break;
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
}