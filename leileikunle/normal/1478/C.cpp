#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int maxnn = 2e5+10;
int a[maxnn];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=2*n;i++) cin>>a[i];
	sort(a+1,a+1+2*n);
	for(int i=1;i<=2*n;i+=2)
	{
		if(a[i]!=a[i+1] || a[i]==a[i+2])
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	int t = 2*n;
	int k = t;
	if(a[t]%k!=0)
	{
		cout<<"NO"<<endl;
		return;
	}else k-=2;
	if(k==0) 
	{
		cout<<"YES"<<endl;
		return;
	}
	int d = a[t]/t;
	for(int i=2*n;i>=3;i-=2)
	{
		int c = a[i]-a[i-2];
		if(c%k!=0)
		{
			cout<<"NO"<<endl;
			return;
		}else{
			int s = c/k;
			d-=s;
			k-=2;
		}
	}
	if(d>0)	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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