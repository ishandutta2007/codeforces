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
ll f(ll a){
    return (a*(a+1))/2;
}
ll g(ll b,ll a){
    return f(b)-f(b-a);
}
void solve(){
    ll n,x;cin>>n>>x;
    ll arr[2*n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[n+i]=arr[i];
    }
    ll dp[2*n+1];
    ll dp2[2*n+1];
    dp[0]=0;
    dp2[0]=0;
    for(int i=1;i<=2*n;i++){
        dp[i]=dp[i-1]+arr[i];
        dp2[i]=dp2[i-1]+f(arr[i]);
    }
    ll ans = 0;
    ll start,end,mid,val;
    for(int i=1;i<=n;i++){
        start = i;end = 2*n;
        while(start<=end){
            mid=(start+end+1)/2;
            if(dp[mid]-dp[i-1]>=x){
                val=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }  
        ans = max(ans,dp2[val-1]-dp2[i-1]+f(x-dp[val-1]+dp[i-1]));
        start = i;end=2*n;
        while(start<=end){
            mid=(start+end+1)/2;
            if(dp[mid]-dp[i]+1>=x){
                val = mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        } 
        ans = max(ans,dp2[val-1]-dp2[i]+arr[i]+f(x-dp[val-1]+dp[i]-1));
    }
    ll brr[2*n+1];
    for(int i=1;i<=2*n;i++){
        brr[2*n-i+1]=arr[i];
    }
    for(int i=1;i<=2*n;i++){
        arr[i]=brr[i];
    }
    dp[0]=0;
    dp2[0]=0;
    for(int i=1;i<=2*n;i++){
        dp[i]=dp[i-1]+arr[i];
        dp2[i]=dp2[i-1]+f(arr[i]);
    }
    for(int i=1;i<=n;i++){
        start = i;end = 2*n;
        while(start<=end){
            mid=(start+end+1)/2;
            if(dp[mid]-dp[i-1]>x){
                val=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }  
        //cout<<dp2[val-1]-dp2[i-1] + g(arr[val],x-dp[val-1]+dp[i-1])<<"\n";
        ans = max(ans,dp2[val-1]-dp2[i-1] + g(arr[val],x-dp[val-1]+dp[i-1]));
        start = i+1;end=2*n;
        while(start<=end){
            mid=(start+end+1)/2;
            if(dp[mid]-dp[i]+1>x){
                val = mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        } 
        //cout<<dp2[val-1]-dp2[i]+1+g(arr[val],x-dp[val-1]+dp[i]-1)<<"\n";
        ans = max(ans,dp2[val-1]-dp2[i]+1+g(arr[val],x-dp[val-1]+dp[i]-1));
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}