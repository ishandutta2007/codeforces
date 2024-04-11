#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
ll arr[100001]{0};
ll dp[100001]{0};
ll  n,a,r,m;
ll moves(ll oo){
    ll ret = 0;
    int start=0,end=n,mid,ans=0;
    while(start<=end){
        mid=(start+end+1)/2;
        if(arr[mid]<=oo){
            start=mid+1;
            ans=mid;
        }else{
            end=mid-1;
        }
    }
    //cout<<oo<<" "<<ans<<" "<<oo*ans-dp[ans]<<" "<<dp[n]-dp[ans]-oo*(n-ans)<<"\n";
    return min(oo*ans-dp[ans],max(dp[n]-dp[ans]-oo*(n-ans),0ll));
}
ll check(ll oo){
    ll ans = moves(oo);
    if(oo*n>=dp[n])
        return ans*m+(oo*n-dp[n])*a;
    else
        return ans*m+(dp[n]-oo*n)*r;
}
void solve(){
    cin>>n>>a>>r>>m;
    m = min(m,a+r);
    vector<ll>v;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        v.pb(arr[i]);
    }
    sort(arr,arr+n+1);
//    cout<<0<<" ";
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+arr[i];
  //      cout<<dp[i]<<" ";
    }
   // cout<<"\n";
    ll curr = dp[n]/n;
    v.pb(curr);
    v.pb(curr+1);
    ll an = 7e18;
    for(auto i:v){
        an=min(an,check(i));
    }
    cout<<an<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
   // cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}