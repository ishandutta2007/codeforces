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
void solve(){
    ll n;cin>>n;
    ll arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    priority_queue<pii>dp[n+1];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[j]<arr[i]){
                dp[i].push({arr[j],j});
            }
        }
    }
    vector<pii>v;
    for(int i=1;i<=n;i++){
        while(dp[i].size()>0){
            auto k =dp[i].top();
            dp[i].pop();
            v.push_back({i,k.second});
        }
    }
    cout<<v.size()<<"\n";
    for(auto i : v){
        cout<<i.F<<" "<<i.S<<"\n";
    }
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