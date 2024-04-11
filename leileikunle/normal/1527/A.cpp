#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define pb push_back 	#define po pop_back
#define YES cout<<"YES\n" 	#define Yes cout<<"Yes\n"   #define NO cout<<"NO\n"	 #define No cout<<"No\n"
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
const int N = 2e5+10;
const int  mod  = 1e18;
inline int quick(int a, int b) { a%=mod; int res = 1;  while(b) { if(b & 1) res = res * a % mod; a = a * a % mod;  b >>= 1; } return res; }

void solve()
{
	int n; cin>>n;
	int t = n;
	int ans = 1,q = 0;
	while(ans<=t)
	{
		ans*=2;
		q++;
	}
	q--;
	cout<<quick(2,q)-1<<endl;
}
signed main()
{
	int tt=1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}



}