#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"YES\n" 	#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"		#define No cout<<"No\n"
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define cn change_number_tostring
#define cs change_string_tonumber
#define pri init_prime_distance
const int mod = 1e9+7;
inline int digit(int i) { stringstream ss; ss<<i; return ss.str().size(); }
inline int quick(int a, int b) { a%=mod; int res = 1;  while(b) { if(b & 1) res = res * a % mod; a = a * a % mod;  b >>= 1; } return res; }

const int N = 2e5+10;
int a[10];
int dp[N];
void solve()
{
	for(int i=0;i<=9;i++) a[i]=0;
	string n; int k; cin>>n>>k;
	int t=n.size();
	for(int i=0;i<t;i++) a[n[i]+2-'2']++;
	int sum = 0;
	for(int i=0;i<=9;i++)
	{
		if(a[i]==0) continue;
		sum+=((a[i]*dp[i+k])%mod);
		sum%=mod;
	}
	cout<<sum<<endl;
}
signed main()
{
	ios;
	int tt; cin>>tt;
	for(int i=0;i<=9;i++) dp[i] = 1;
	for(int i=10;i<=N;i++) dp[i] = (dp[i-9]+dp[i-10])%mod;
	while(tt--)
	{
		solve();	
	}


}