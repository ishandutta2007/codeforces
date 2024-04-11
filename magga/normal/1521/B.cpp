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
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll mi = 1e10;
    ll argmin = -1;
    for(int i=0;i<n;i++){
        if(arr[i]<mi){
            mi = arr[i];
            argmin = i;
        }
    }
    vector<pair<pii,pii>>v;
    if(argmin!=0){
        v.push_back({{0,argmin},{mi,mi}});
    }
    for(int i=1;i<n;i++){
        if(i%2==1){
            v.push_back({{0,i},{mi,mi+1}});
        }else{
            v.push_back({{0,i},{mi,mi}});
        }
    }
    cout<<v.size()<<"\n";
    for(auto i:v){
        cout<<i.F.F+1<<" "<<i.F.S+1<<" "<<i.S.F<<" "<<i.S.S<<"\n";
    }
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