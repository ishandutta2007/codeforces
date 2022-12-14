#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
signed main() 
{
	int t ;cin>>t;
	while(t--)
	{
		int n,d; cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(a[n]<=d || a[1]+a[2]<=d) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}