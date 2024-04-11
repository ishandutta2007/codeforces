
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>    
    
void pre(){}
void solve(){
    ll n,m;cin>>n>>m;
    pii arr[n*m];
    for(int i=0;i<n*m;i++){
        cin>>arr[i].F;
        arr[i].S = i;
    }
    sort(arr,arr+n*m);
    ll ans = 0;
    for(int i=0;i<n;i++){
        ordered_set os;
        for(int j=0;j<m;j++){
            arr[i*m+j].S = 1e6 - arr[i*m+j].S;
        }
        sort(arr+i*m,arr+(i+1)*m);
        for(int j=0;j<m;j++){
            arr[i*m+j].S = 1e6 - arr[i*m+j].S;
        }
        for(int j=0;j<m;j++){
            ans+=os.order_of_key(arr[i*m+j].S);
            //cout<<os.order_of_key(arr[i*m+j].S)<<"\n";
            os.insert(arr[i*m+j].S);
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