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
void eat(){
    // ohh LMAO THIS IS THE TASK KEVIN USED TO WRITE TASK
    // (lscct comp in case you were wondering)
    int n;
    cin>>n;
    int arr[n],freq[64]={};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<63;j++)freq[j]+=((arr[i]>>j)&1);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int x=0,y=0;
        for(int j=0;j<63;j++){
            if((arr[i]>>j)&1){
                (x+=((1ll<<j)%mod*freq[j])%mod)%=mod;
                (y+=((1ll<<j)%mod*n)%mod)%=mod;
            }
            else (y+=((1ll<<j)%mod*freq[j])%mod)%=mod;
        }
        (ans+=(x*y)%mod)%=mod; // diu
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}