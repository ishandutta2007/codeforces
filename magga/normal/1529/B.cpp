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
// Please write the recurances once :(
void pre(){}
void solve(){
    ll n;cin>>n;
    vector<ll>v[3];
    ll d;
    for(int i=0;i<n;i++){
        cin>>d;
        if(d>0){
            v[2].pb(d);
        }else if(d==0){
            v[1].pb(d);
        }else{
            v[0].pb(d);
        }
    }
    ll ans = max(1ll,ll(v[0].size()+v[1].size()));
    if(v[2].size()>0){
        if(v[1].size()>0)
            v[0].push_back(0);
        sort(v[0].begin(),v[0].end());
        sort(v[2].begin(),v[2].end());
        ll diff = v[2][0];
        ll curr = 1;
        ll last = diff;
        for(int i=v[0].size()-1;i>=0;i--){
            if(abs(last-v[0][i])>=diff){
                last = v[0][i];
                curr++;
            }
        }
        ans = max(ans,curr);
    }
    cout<<ans<<"\n";   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}