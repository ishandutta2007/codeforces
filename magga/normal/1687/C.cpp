#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
void solve(){
    int n,m,u,v;cin>>n>>m;
    set<int>left;
    for(int i=1;i<=n;i++) left.insert(i);
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    ll d;
    for(int i=0;i<n;i++){
        cin>>d;
        arr[i]-=d;
    } 
    vector<int>g[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        u--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    queue<int>q;
    ll curr = 0;
    q.push(0);
    bool flag[n+1];
    for(int i=0;i<=n;i++) flag[i]=0;
    flag[0]=1;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(curr==0){
            flag[i+1]=1;
            q.push(i+1);
            left.erase(i+1);
        }
    }
    while(q.size()>0){
        auto i = q.front();
        q.pop();
        for(auto j:g[i]){
            int start = min(i,j);
            int end   = max(i,j);
            if(flag[start] && flag[end]){
                while(left.size()>0){
                    auto poit = left.lower_bound(start);
                    if(poit==left.end()) break;
                    if((*poit)>end) break; 
                    q.push(*poit);
                    flag[*poit] = 1;
                    left.erase(poit);
                }
            }
        }   
    }
    if(left.size()==0){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
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