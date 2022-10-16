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
    vector<pii>ans;
    ll j;
    for(int i=0;i<n;i++){
        j = 5*i;
        ans.push_back({j,0});
        ans.push_back({j,1});
        ans.push_back({j,2});
        ans.push_back({j,-1});
        ans.push_back({j,-2});
        ans.push_back({j+1,0});
        ans.push_back({j+2,0});
        ans.push_back({j-1,0});
        ans.push_back({j-2,0});
        if(i%2==0){
            ans.push_back({j+1,2});
            ans.push_back({j+2,2});
            ans.push_back({j-1,-2});
            ans.push_back({j-2,-2});
        }else{
            ans.push_back({j+1,-2});
            ans.push_back({j+2,-2});
            ans.push_back({j-1,2});
            ans.push_back({j-2,2});
        }
    }
    ans.push_back({-2,-1});
    j = 5*(n-1);
    if(n%2==0){
        ans.push_back({j+2,-1});
    }else{
        ans.push_back({j+2,1});
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.F<<" "<<i.S<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}