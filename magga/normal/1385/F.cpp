#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
vector<int>arr[200005];
long long int dp[200005]{0};
long long int dp2[200005]{0};
ll n,u,v,w,k;
ll ans = 0;
ll curr = 0;
ll dfs(int i,int from){
    for(auto to:arr[i]){
        if(to!=from){
            dp[i]+=dfs(to,i);
            dp2[i]++;
        }
    }
    curr+=dp[i]/k;
    if(dp[i]%k==0 && dp[i]==dp2[i]){
        return 1;
    }else{
        return 0;
    }
}
void dfs2(int i,int from){
    ans = max(ans,curr);
    for(auto to:arr[i]){
        if(to!=from){
            ll a = dp[to];
            ll b  = dp[i];
            ll c = curr;
            curr-=dp[i]/k;
            curr-=dp[to]/k;
            if(dp[to]%k==0 && dp2[to]==dp[to]){
                dp[i]--;
            }
            dp2[i]--;
            dp2[to]++;
            if(dp[i]%k==0 && dp2[i]==dp[i]){
                dp[to]++;
            }
            curr+=dp[i]/k;
            curr+=dp[to]/k;
            ans = max(ans,curr);
            dfs2(to,i);
            dp2[to]--;
            dp2[i]++;
            dp[to] = a;
            dp[i] = b;
            curr = c; 
        }
    }
}
void pre(){}
void solve(){
    cin>>n>>k;
    ans = 0;
    curr = 0;
    for(int i=0;i<=n;i++){
        arr[i].clear();
        dp[i] = 0;
        dp2[i] = 0;
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }   
    dfs(1,0);
    ans = curr;
    dfs2(1,0);
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll num;
    cin>>num;
    for(long long int i=0;i<num;i++){
        solve();
    }   
}