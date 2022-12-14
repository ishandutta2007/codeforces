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
const int ma = 1e5+10;
using namespace std;

//int a[ma],b[ma];
int dp[ma][2];
int n;
struct s{
	int maxn;
	int ans;
	int cha;
}a[ma];
int b[ma];
signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		cin>>n;
		for1 cin>>a[i].ans, a[i].cha = 0;
		a[1].maxn = a[1].ans;
		int t = 1;
		for2(i,2,n)
		{
			if(a[i].ans>a[i-1].maxn) a[i].maxn = a[i].ans;
			else 	a[i].maxn = a[i-1].maxn;
		}
		for3(i,n,1)
		{
			if(a[i].ans!=a[i].maxn) t++;
			else
			{
				a[i].cha = t; t = 1;
			}
		}
		int y = 1;
		int u = 1;
		for3(i,n,1)
		{
			b[y] = a[i].ans; y++;
			if(a[i].cha!=0)
			{
				reverse(b+u,b+u+a[i].cha);
				u+=a[i].cha;
			}
			
		}
		for1 cout<<b[i]<<" ";
		cout<<'\n';
	}
	
}