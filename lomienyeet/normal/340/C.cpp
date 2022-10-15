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
    int arr[n],s=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s+=arr[i];
    }
    sort(arr,arr+n);
    int ps[n]={};
    ps[0]=arr[0];
    for(int i=1;i<n;i++)ps[i]=ps[i-1]+arr[i];
    int ans=0;
    for(int i=1;i<n;i++)ans+=i*arr[i]-ps[i-1];
    (ans*=2)+=s;
    int g=gcd(ans,n);
    cout<<ans/g<<" "<<n/g<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}