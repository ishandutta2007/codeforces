#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
                
#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pretime float(clock()-clk)/CLOCKS_PER_SEC
#define max2(a,b) ((a)>(b) ? (a) : (b))   
#define min2(a,b) ((a)<(b) ? (a) : (b)) 
#define rep(i,a,b) for(i=a;i<=b;++i)
#define rev(i,a,b) for(i=a;i>=b;--i) 
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define ll long long int 
#define ins insert
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define PI 3.14159265
#define mod 1000000007
#define inf 1000000000000000
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'

using namespace std;
typedef vector<ll>   vll;
typedef vector<int>   vi;
typedef set<ll>      sll;
typedef set<int>      si;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
clock_t clk=clock();       

ll i,j;
void solve(void);

int main()
{
  speedio;
   int t=1;  
  // cin>>t;
   while(t--)
     solve();

  return 0;
}

double power(double x,ll n)
{ 
  double res=1;  	//x%=m; 
     while(n>0)
       { 
         if(n&1==1) res=(res*x);
          n/=2;
          x=(x*x);
       }
   return res;
}

	double dp[5005][5005];
// #define cerr if(0)cerr
void solve()
{
	ll n,T; cin>>n>>T;

	double p[n+1]={0}; int t[n+1]={0};
	rep(i,1,n)
	{
		double pr; cin>>pr>>t[i];
		p[i]=pr/100;
	}

	dp[0][0]=1; double ans=0.0;

	rep(i,1,n)
	{ double pwr=power(1-p[i],t[i]);
	  rep(j,i,T)
	  {
	  	 dp[i][j]=dp[i][j-1]*(1-p[i])+dp[i-1][j-1]*p[i];

	  	 if(j-t[i]>=0)
	  	 	dp[i][j]+=dp[i-1][j-t[i]]*pwr;
	  	 if(j-t[i]-1>=0)
	  	 	dp[i][j]-=dp[i-1][j-t[i]-1]*pwr;

         if(dp[i][j]<(1e-100)) dp[i][j]=0;
         
	  	 ans+=dp[i][j];
	  }
	}
    
    cout<<fixed<<setprecision(10)<<ans<<'\n';
}