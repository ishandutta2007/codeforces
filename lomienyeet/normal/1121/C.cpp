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
const int mxN=2e5+5;
int bit[mxN]={};
int eat(int x,int y){
    int z=100*x/y;
    if(((100*x)%y)*2<y)return z;
    else return z+1;
}
void upd(int x){
    for(;x<mxN;x+=x&-x)bit[x]++;
}
int qry(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=bit[x];
    return ans;
}
void pau_txdy(){
    int n,k;
    cin>>n>>k;
    int arr[n],dp[n][5005];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<n;j++)dp[i][j]=0;
    }
    multiset<int> ms;
    for(int i=0;i<k;i++)ms.insert(0);
    for(int i=0;i<n;i++){
        auto x=*(ms.begin());
        for(int j=1;j<=arr[i];j++)dp[i][j]=j+x;
        upd(arr[i]+x);
        ms.erase(ms.begin());
        ms.insert(arr[i]+x);
    }
    set<int> s;
    for(int i=0;i<n;i++){
        for(int j=1;j<=arr[i];j++){
            if(eat(qry(dp[i][j]-1),n)==j)s.insert(i);
        }
    }
    cout<<s.size()<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)pau_txdy();
}