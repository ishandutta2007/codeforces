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
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll n,m,u,v;cin>>n>>m;
    multiset<ll>arr[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].insert(v);
    }
    for(ll i=1;i<=n;i++){
        ll a = 0;
        for(ll j=1;j<=n;j++){
            if(arr[j].size()==0){
                continue;
            }
            ll b = (j - i + n)%n + (arr[j].size())*n;
            ll c = b-n;
            auto u = arr[j].lower_bound(j);
            if(u==arr[j].end()){
                c+=(*arr[j].begin()-j+n)%n;
            }else{
                c+=(*u-j+n)%n;
            }
            a=max(a,c);
        }
        cout<<a<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}