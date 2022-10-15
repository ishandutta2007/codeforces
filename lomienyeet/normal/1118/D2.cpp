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
int n,m,arr[200005],ps[200005];
bool ok(int x){
    int cur=0,ptr=0,cnt=0;
    for(int i=n;i>0;i--){
        if(arr[i]<=ptr)break;
        cur+=arr[i]-ptr;
        cnt++;
        if(cnt==x){
            cnt=0;
            ptr++;
        }
    }
    return cur>=m;
}
void eat(){
    /*
    
    
    */
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++)ps[i]=ps[i-1]+arr[i];
    int ans=-1,lb=1,ub=n;
    while(lb<=ub){
        int mid=(lb+ub)>>1;
        if(ok(mid)){
            ans=mid;
            ub=mid-1;
        }
        else lb=mid+1;
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