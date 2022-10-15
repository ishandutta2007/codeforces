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
    // solve
    int n;string a,b;
    cin>>n>>a>>b;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        x+=(a[i]==b[i]);
        y+=(a[i]!=b[i]);
    }
    int ans=1e18;
    if(x&1){
        int c=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])continue;
            if(a[i]=='1')c++;
        }
        if(c==(x>>1)+1)ans=min(ans,x);
    }
    if(!(y&1)){
        int z=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i])continue;
            if(a[i]=='1')z++;
        }
        if(z==(y>>1))ans=min(ans,y);
    }
    cout<<(ans==1e18?-1:ans)<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}