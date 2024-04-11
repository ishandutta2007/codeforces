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

int a[ma],b[ma];
int dp[ma][2];
int n;

signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a%b==0||a%c==0||a%d==0)
		{
			cout<<0<<"\n";
			continue;
		}else
		{
			int minn = min(min(b,c),d);
			if(a<minn)
			{
				cout<<minn-a<<'\n';
				continue;
			}
			int t1 = b*(a/b+1)-a;
			int t2 = c*(a/c+1)-a;
			int t3 = d*(a/d+1)-a;
			cout<<min(min(t1,t2),t3)<<"\n";
		}
	}
	
}