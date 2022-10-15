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
void eat(){
    /*
    */
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    pair<int,int> dp[n+2][2];
    for(int i=1;i<=n+1;i++)dp[i][0]=dp[i][1]={0,0};
    for(int i=n;i>0;i--){
        for(int j=0;j<2;j++){
            if(!j){
                if(dp[i+1][j^1].ss+arr[i]>dp[i+1][j].ss){
                    dp[i][j]=dp[i+1][j^1];
                    dp[i][j].ss+=arr[i];
                }
                else{
                    dp[i][j]=dp[i+1][j];
                    dp[i][j].ff+=arr[i];
                }
            }
            else{
                if(dp[i+1][j^1].ff+arr[i]>dp[i+1][j].ff){
                    dp[i][j]=dp[i+1][j^1];
                    dp[i][j].ff+=arr[i];
                }
                else{
                    dp[i][j]=dp[i+1][j];
                    dp[i][j].ss+=arr[i];
                }
            }
        }
    }
    cout<<dp[1][1].ss<<" "<<dp[1][1].ff<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}