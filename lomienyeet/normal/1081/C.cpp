// got rid of my other template because *a few people will complain*
#include <bits/stdc++.h>
// #include <bits/extc++.h> // use if non-cf & non-c++20
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> // use if cf & C++20 (iconv.h got deprecated or sth i dont remember)
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
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
const int mxN=2505;
int dp[mxN][mxN];
void eat(){
    /* 
     */
    // what the fuck
    int n,m,k;
    cin>>n>>m>>k;
    if(n==1){
        cout<<m<<"\n";
        return;
    }
    dp[n][0]=1;
    dp[n][1]=m-1;
    for(int i=n-1;i>1;i--){
        for(int j=1;j<=k;j++)dp[i][j]=(dp[i+1][j]+dp[i+1][j-1]*(m-1))%mod2;
        dp[i][0]=dp[i+1][0];
    }
    cout<<(dp[2][k]*m)%mod2<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}