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
int qry(int x){
    cout<<x<<"\n";
    fflush(stdout);
    int ans;
    cin>>ans;
    if(!ans)exit(0);
    return ans;
}
void solve(){
    int m,n;
    cin>>m>>n;
    int arr[n];
    for(int i=0;i<n;i++)arr[i]=qry(1);
    int lb=2,rb=m,w=0;
    while(lb<rb){
        int mid=(lb+rb)>>1;
        if(qry(mid)*arr[w%n]==1)lb=mid+1;
        else rb=mid;
        w++;
    }
    qry(lb);
    return;
}
signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
}