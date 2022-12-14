#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
using namespace std;

const int N = 1e4+10;
 int a[N];
void solve()
{
	int n; cin>>n;
	if(n==1)
	{
		cout<<1<<endl;
		return;
	}
	if(n==2)
	{
		cout<<-1<<endl;
		return;
	}
	int t = (n*n+1)/2;
	int cnt = 0;
	int cun = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[cun]<<" ";
			cun+=2; cnt++;
			if(cnt==t)
			{
				cun=2;
			}
		}
		cout<<endl;
	}
}
signed main()
{
	ios;
	for(int i=1;i<=N;i++) a[i]=i;
	int tt = 1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
}