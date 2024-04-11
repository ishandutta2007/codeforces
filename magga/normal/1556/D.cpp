
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
ll andq(int i,int j){
    i++;j++;
    cout<<"and"<<" "<<i<<" "<<j<<"\n";
    cout.flush();
    ll ret;cin>>ret;
    return ret;
}
ll orq(int i,int j){
    i++;j++;
    cout<<"or"<<" "<<i<<" "<<j<<"\n";
    cout.flush();
    ll ret;cin>>ret;
    return ret;
}
void res(ll ans){
    cout<<"finish "<<ans<<"\n";
    cout.flush();
}
void pre(){}
void solve(){
    ll n,k;cin>>n>>k;
    ll ands[n];
    ll ors[n];
    ll arr[n];
    for(int i=1;i<n;i++){
        ands[i] = andq(0,i);
        ors[i] = orq(0,i);
    }
    ll ora = ors[1];
    ll anda = ands[1];
    for(int i=1;i<n;i++){
        anda |= ands[i];
        ora &= ors[i];
    }
    ll outer = andq(1,2);
    ora = (ora&outer)^ora;
    arr[0] = anda|ora;
    for(int i=1;i<n;i++){
        arr[i] =  ands[i]|(ors[i]^arr[0]);
    }
    sort(arr,arr+n);
    res(arr[k-1]);
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