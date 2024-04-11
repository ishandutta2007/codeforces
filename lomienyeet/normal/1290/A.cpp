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
const int mxN=4e3+505;
int n,m,k,arr[mxN];
bool eat(int x){
    int fuck[n],fuck2[n];
    for(int i=0;i<n;i++){
        if(arr[i]>=x)fuck[i]=1;
        else fuck[i]=0;
    }
    for(int i=0;i<n;i++){
        if(m-i>0)fuck2[i]=max(fuck[i],fuck[n-m+i]);
        else fuck2[i]=0;
    }
    int ps[n+1]={};
    for(int i=1;i<=n;i++)ps[i]=ps[i-1]+fuck2[i-1];
    bool fucked=0;
    for(int i=0;i<=k;i++){
        int y=m-k-1;
        if(ps[i+y+1]-ps[i]==y+1)fucked=1;
    }
    return fucked;
}
void orz_73(){
    // is nicholask afk?
    cin>>n>>m>>k;
    k=min(k,m-1);
    for(int i=0;i<n;i++)cin>>arr[i];
    int lb=0,rb=1e18;
    while(lb+1<rb){
        int mid=(lb+rb)>>1;
        if(eat(mid))lb=mid;
        else rb=mid;
    }
    cout<<lb<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)orz_73();
}