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
    ll n,u,v;cin>>n;
    ll arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    priority_queue<ll>pq;
    ll ans = 0;
    set<ll>s;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        if(s.find(u)!=s.end()){
            pq.push(arr[u]);
        }else{
            ans+=arr[u];
            s.insert(u);
        }
        if(s.find(v)!=s.end()){
            pq.push(arr[v]);
        }else{
            ans+=arr[v];
            s.insert(v);
        }
    }
    for(int i=n-2;i>=0;i--){
        cout<<ans<<" ";
        //cout.flush();
        if(pq.size()>0){
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<"\n";
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