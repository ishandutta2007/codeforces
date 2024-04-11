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
    int n,k;string s;
    cin>>n>>k>>s;
    if(s.find("W")==string::npos){
        cout<<max(0ll,(k<<1)-1)<<"\n";
        return;
    }
    s="_"+s;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='W')ans+=(s[i-1]=='W')+1;
    }
    int lb=1,rb=n;
    while(lb<=n&&s[lb]=='L')lb++;
    while(rb>0&&s[rb]=='L')rb--;
    multiset<int> ms;
    int l=lb,r=lb;
    while(l<=rb){
        r=l+1;
        while(r<=rb&&s[r]=='L')r++;
        if(r-l-1>0)ms.insert(r-l-1);
        l=r;
    }
    while(ms.size()){
        auto x=*ms.begin();
        if(!k){
            ms.clear();
            break;
        }
        if(k>=x){
            ans+=(x<<1)+1;
            k-=x;
        }
        else{
            ans+=(k<<1);
            k=0;
        }
        ms.erase(ms.begin());
    }
    if(k>0){
        ans+=(min(n-rb,k)<<1);
        k-=min(n-rb,k);
        if(!k)goto fuck;
        ans+=(min(k,lb-1)<<1);
    }
    fuck:;
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