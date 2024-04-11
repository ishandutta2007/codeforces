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
    priority_queue<pair<ll,pii>>pq;
    set<ll>f;
    set<ll,greater<>>b;
    for(int i=-1;i<n+1;i++) f.insert(i);
    for(int i=-1;i<n+1;i++) b.insert(i);
    int ans = 0;
    vector<int> print_order;
    for(int i=0;i<n;i++){
        if(__gcd(arr[i],arr[(i+1)%n])==1){
            pq.push({0,{-1*i,-1*((i+1)%n)}});
        } 
    }
    while(pq.size()>0){
        auto i = pq.top();
        pq.pop();
        i.F*=-1;
        i.S.F*=-1;
        i.S.S*=-1;
        if(f.find(i.S.F)==f.end() || f.find(i.S.S)==f.end()){
            continue;
        }
        ans++;
        print_order.push_back(i.S.S);
        f.erase(i.S.S);
        b.erase(i.S.S);
        if(f.size()==2){
            break;
        }
        int next = *f.upper_bound(i.S.F);
        if(next==n){
            next = *f.upper_bound(-1);
        }
        //cout<<next<<"\n";
        if(__gcd(arr[i.S.F],arr[next])==1){
            pq.push({-1*(i.F+1),{-1*i.S.F,-1*next}});
        }
        // int prev = *b.upper_bound(i.S.F);
        // if(prev==-1){
        //     prev = *b.upper_bound(n);
        // }
        // if(__gcd(i.S.F,arr[prev])==1){
        //     pq.push({-1*(i.F+1),{-1*prev,-1*i.S.F}});
        // }
    }
    cout<<ans<<" ";
    for(auto i:print_order){
        cout<<i+1<<" ";
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