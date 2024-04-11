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

const int N = 2e5+10;
int flag;
int q;
int judge(int t,int n)
{
	q=2;
	for(int i=t;i<= n;) 
	{
		if (i*q*q>n)  break;
		if (i*q*q==n) 
		{
			flag = 1;
			break;
		}
		q++;
	}
	if(flag) return 1;
	else return 0;
}
void solve()
{
	flag = 0;
	int n; cin>>n;
	if(n==2||n==4)
	{
		cout<<"YES"<<endl;
		return;
	}
	flag = judge(4,n);
	flag = judge(2,n);
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios;
	int tt = 1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
	


}