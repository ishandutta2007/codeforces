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
    ll n,m;cin>>n>>m;
    pii arr[n*m];
    ll ans[n][m];
    multiset<pii>store;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i*m+j].F;
            arr[i*m+j].S = i; 
            store.insert({arr[i*m+j].F,i});
            ans[i][j]=-1;
        }
    }
    sort(arr,arr+n*m);
    int pointers[n];
    for(int i=0;i<n;i++) pointers[i]=0;
    for(int i=0;i<m;i++){
        auto p = arr[i];
        ans[p.S][i] = p.F;
    }
    for(int i=m;i<m*n;i++){
        while(ans[arr[i].S][pointers[arr[i].S]]!=-1) pointers[arr[i].S]++;
        ans[arr[i].S][pointers[arr[i].S]] = arr[i].F;
        pointers[arr[i].S]++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
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