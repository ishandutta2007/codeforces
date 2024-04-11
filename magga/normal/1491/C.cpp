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
void pre(){}
void solve(){
    ll n;cin>>n;
    ll arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    set<ll>s;
    for(int i=1;i<=n;i++){
        if(arr[i]!=1){
            s.insert(i);
        }
    }
    s.insert(1e18);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(arr[i]==1){
            continue;
        }
        if(arr[i]>n+1){
            ans+=arr[i]-n-1;
            arr[i]=n+1;
        }
        ll curr = i;
        while(arr[i]>1){
            curr = i;
            ans++;
            while(curr<=n){
                ll t = curr;
                curr+=arr[curr];
                arr[t]=max(arr[t]-1,1ll);
                if(arr[t]==1){
                    s.erase(t);
                }
                curr = *s.lower_bound(curr);
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