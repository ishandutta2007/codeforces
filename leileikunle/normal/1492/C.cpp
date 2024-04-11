#include<bits/stdc++.h>
#define int long long
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
const int mod = 1e9+7;
const int sp = 1e9;
const int ma = 2e5+10;
using namespace std;

char p[ma],q[ma];  
int qq[ma],pp[ma]; 
int n;

signed main()
{
	ios;
	int n,m; cin>>n>>m;
	pp[m+1] = n+1;
	for1 cin>>p[i];  for2(i,1,m) cin>>q[i];
	for2(i,1,m) for(qq[i] = qq[i-1]+1;p[qq[i]]!=q[i];qq[i]++);
	for3(i,m,1) for(pp[i] = pp[i+1]-1;p[pp[i]]!=q[i];pp[i]--);
	int maxn = 1;
	qq[0] = qq[1];
	for3(i,m,1)
	{
		maxn = max(maxn,pp[i]-qq[i-1]);
	}
	cout<<maxn<<'\n';
}