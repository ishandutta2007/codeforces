// wow! so little people watch this match!

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7;
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
/* distraction below (use this cus high, 73 is going to kill me):
#####  #####  #####        #####  #####        #####  #####        #####  #   #  #####  #####        #   #  #   #  #   #
  #      #    #   #          #    #            #      #   #        #      #   #    #    #            #   #  #   #  #   #
  #      #    #   #          #    #####        #####  #   #        #      #   #    #    #####        #   #  #   #  #   #
  #      #    #   #          #        #            #  #   #        #      #   #    #    #            #   #  # # #  #   #
#####    #    #####        #####  #####        #####  #####        #####  #####    #    #####        #####  ## ##  ##### */
void eat(){
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    int dp[n+1][m+1],ans=0;
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)dp[i][j]=dp[i][j-1]+(s[i-1][j-1]=='1');
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=i;k<=n;k++){
                for(int l=j;l<=m;l++){
                    bool z=0;
                    for(int a=i;a<=k;a++)z|=(dp[a][l]-dp[a][j-1]>0);
                    if(!z)ans=max(ans,2*(k+l-i-j+2));
                }
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}