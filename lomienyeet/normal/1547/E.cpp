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
    int n,k;
    cin>>n>>k;
    int arr[k+1],mp[n+1];
    for(int i=1;i<=n;i++)mp[i]=2e9;
    for(int i=1;i<=k;i++)cin>>arr[i];
    for(int i=1,x;i<=k;i++){
        cin>>x;
        mp[arr[i]]=x;
    }
    for(int i=2;i<=n;i++)mp[i]=min(mp[i],mp[i-1]+1);
    for(int i=n-1;i>0;i--)mp[i]=min(mp[i],mp[i+1]+1);
    for(int i=1;i<=n;i++)cout<<mp[i]<<" ";
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