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
    int n;
    cin>>n;
    int arr[n+1],xs=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        xs^=arr[i];
    }
    if(!xs){
        cout<<"YES\n";
        return;
    }
    int ans=0,wa=0;
    for(int i=1;i<=n;i++){
        wa^=arr[i];
        if(wa==xs){
            ans++;
            wa=0;
        }
    }
    cout<<((ans>2&&!wa)?"YES\n":"NO\n");
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}