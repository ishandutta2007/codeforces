#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int a[200002] = {0};
		int l = 0, r = 0;
		int n,k; cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		l = r = a[1];
		int i; for(i=2;i<=n;i++)
		{
			l = max(a[i],l-k+1);
			r = min(a[i]+k-1,r+k-1);
			if(l>r) break;
		}
		if(i>n && a[n] == l) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}