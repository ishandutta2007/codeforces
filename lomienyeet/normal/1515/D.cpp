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
    int n,l,r;
    cin>>n>>l>>r;
    int a[n+1]={},b[n+1]={};
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(i<=l)a[x]++;
        else b[x]++;
    }
    for(int i=1;i<=n;i++){
        int ee=min(a[i],b[i]);
        l-=ee;
        r-=ee;
        a[i]-=ee;
        b[i]-=ee;
    }
    if(l>r){
        swap(l,r);
        for(int i=1;i<=n;i++)swap(a[i],b[i]);
    }
    int aaa=0;
    for(int i=1;i<=n;i++){
        int way1=(r-l)/2,way2=b[i]/2;
        int z=min(way1*2,way2*2);
        aaa+=z/2;
        r-=z;
    }
    cout<<aaa+r<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}