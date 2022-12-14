#include<bits/stdc++.h>
#define int long long
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define for0 for(int i=0;i<n;i++) cin>>a[i];
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
const int ma = 1e4+10;
using namespace std;
int a[ma];
void solve()
{
	int n; cin>>n;
	for0; 

		for(int i=0;i<n;i++)
		{
			if(a[i]<i) 
			{
				NO; return;
			}else{
				a[i+1] += a[i]-i;
			}
		}
		YES; return;


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