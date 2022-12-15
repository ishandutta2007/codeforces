#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int maxnn = 1e5+10;
int a[maxnn];
void solve()
{
	int n,k; 
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int sum = 0;
	int sum1 = 0;
	for(int i=1;i<=n-1;i++)
	{
		sum+=a[i];
		if(a[i+1]*100>k*sum) 
		{
			int t = a[i+1]*100/k;
			if((1ll*a[i+1]*100)%k!=0) t++;
			sum1 = max(sum1,t-sum);
		}
	}
	cout<<sum1<<endl;
	return;
}
signed main()
{
	ios;
	int tt; cin>>tt; 
	while(tt--)
	{
		solve();
	}
}