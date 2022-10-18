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
// Don't write trash code
void pre(){}
bool intersect(pii a,pii b){
    int ss = min(a.F,a.S);
    int ff = max(a.F,a.S);
    int count = 0;
    if(b.F>ss && b.F<ff) count++;
    if(b.S>ss && b.S<ff) count++;
    if(count==1) return true;
    return false;
}
void solve(){
    ll n,k;cin>>n>>k;
    pii arr[n];
    set<int>s;
    for(int i=0;i<2*n;i++) s.insert(i+1);
    for(int i=0;i<k;i++){
        cin>>arr[i].first>>arr[i].second;
        s.erase(arr[i].F);
        s.erase(arr[i].S);
    }
    vector<int>v;
    for(auto i:s) v.pb(i);
    for(int i=0;i<v.size()/2;i++){
        arr[i+k]={v[i],v[i+v.size()/2]};
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(intersect(arr[i],arr[j])){
                ans++;
            }
        }
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