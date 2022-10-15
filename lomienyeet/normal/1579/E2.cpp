#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
template<typename T> using OST=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
    int n;
    cin>>n;
    OST<int> oset; // thank god i have this in my fucking template
    int ans=0;
    // or maybe, this is just stupid language problem again...
    for(int i=0,x;i<n;i++){
        cin>>x;
        int owo=oset.order_of_key(x),qwq=i-owo,awa=min(owo,qwq);
        owo=oset.order_of_key(x+1),qwq=i-owo,awa=min({awa,owo,qwq});
        ans+=awa;
        oset.insert(x);
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