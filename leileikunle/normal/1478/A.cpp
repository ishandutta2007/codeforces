#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int size = 1e5+10;
int a[105];
signed main()
{
	ios;
	int tt; cin>>tt; 
	while(tt--)
	{
		memset(a,0,sizeof(a));
		int n; cin>>n;
		int maxn = 0;
		for(int i=1;i<=n;i++)
		{
			int t; cin>>t;
			a[t]++;
			maxn=max(maxn,a[t]);
		}
		cout<<maxn<<endl;
	}
 }