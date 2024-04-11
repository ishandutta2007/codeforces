#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7,mod2=998244353,inf=1e18;
void yes(){cout<<"YES\n";}
void no(){cout<<"NO\n";}
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
const int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
void eat(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=1;i<=n;i++)cin>>arr[i];
    int dp[n+5][n+5],bruh[n+5]={};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)dp[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j])+arr[i];
            if(j>0)dp[i][j]=max(dp[i][j],max(0ll,dp[i-1][j-1])+arr[i]+x);
            bruh[j]=max(bruh[j],dp[i][j]);
        }
    }
    for(int i=0;i<=n;i++)cout<<bruh[i]<<" ";
    cout<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}