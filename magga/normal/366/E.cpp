#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
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
ll dist(pii a,pii b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
void solve(){
    ll n,m,k,s;cin>>n>>m>>k>>s;
    pii best[k+1][4];
    int arr[n][m];
    vector<pii>ind[k+1];
    for(int i=0;i<=k;i++){
        best[i][0]={0,0};
        best[i][1]={n,0};  
        best[i][2]={0,m};  
        best[i][3]={n,m};     
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            ind[arr[i][j]].push_back({i,j});
            if(dist({i,j},{0,0})>dist({0,0},best[arr[i][j]][0])){
                best[arr[i][j]][0]={i,j};
            }
            if(dist({i,j},{n,0})>dist({n,0},best[arr[i][j]][1])){
                best[arr[i][j]][1]={i,j};
            }
            if(dist({i,j},{0,m})>dist({0,m},best[arr[i][j]][2])){
                best[arr[i][j]][2]={i,j};
            }
            if(dist({i,j},{n,m})>dist({n,m},best[arr[i][j]][3])){
                best[arr[i][j]][3]={i,j};
            }
        }
    }
    ll poop[10][10]{0};
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(auto k:ind[i]){
                for(auto l:best[j]){
                    poop[i][j]=max(dist(l,k),poop[i][j]);
                }
            }
        }
    }
    ll ans = 0;
    ll brr[s];
    for(int i=0;i<s;i++){
        cin>>brr[i];
    }
    for(int i=1;i<s;i++){
       // cout<<poop[brr[i-1]][brr[i]]<<" ";
        ans = max(ans,poop[brr[i-1]][brr[i]]);
    }
    //cout<<"\n";
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}