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
    ll n,k;cin>>n>>k;
    ll arr[k];
    rep(i,k)cin>>arr[i];    
    vector<ll>v;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    int curr=0;
    rep(i,k){
        ll next = (curr+arr[i])%v.size();
        curr = (curr+1+arr[i])%v.size();
        if(curr>next){
            curr--;
        }
        cout<<v[next]<<" ";
        v.erase(v.begin()+next);
        //cout<<v[curr]<<"\n";
        //cout<<v[next]<<" ";
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