#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back 	#define po pop_back
#define YES cout<<"YES\n" 	#define Yes cout<<"Yes\n"   #define NO cout<<"NO\n"	 #define No cout<<"No\n"
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define cn change_number_tostring    #define cs change_string_tonumber   #define pri init_prime_distance
#define all(a) begin(a), end(a)
#define SUM(a) accumulate(all(a), 0LL)
#define MIN(a) (*min_element(all(a)))
#define MAX(a) (*max_element(all(a)))
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define ub(a, x) distance(begin(a), upper_bound(all(a), (x)))
#define gcd __gcd
#define debug(x) cout<<"x="<<x<<endl
const int N = 2e6;
using namespace std;
const int maxn = 1e5+10;
int a[maxn];
int dp[N];
void print(int x) { cout<<x<<endl; }
int n,cnt,sum;
void solve()
{
	dp[0]=1;
	cin>>n;
    for1 cin>>a[i];
    for1 cnt=max(cnt,a[i]), sum+=a[i];
    for1 for(int j=maxn;j>=a[i];j--) dp[j]|=dp[j-a[i]];
    if(sum%2==0&&dp[sum/2]==0)
    {
        print(0); return;
    }
    int ans=1;
    while(ans<=cnt)
    {
        int t=0,flag=0;
        for1
        {
            t+=a[i]/ans;
            if((a[i]/ans)%2==1) flag=i;
        }
        if(t%2==1)
        {
            print(0);
            return;
        }
        if(flag)
        {
            print(1); print(flag);
            return;
        }
        ans*=2;
        
    }
    cout<<0<<endl;
    return;
}
signed main()
{
	ios;
	int tt = 1;
	//cin>>tt;
	while(tt--)
	{
		solve();
	}

}