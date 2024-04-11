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

const long long int mod = 998244353;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
long long int val[1001];
vector<long long int>arr[1001];
int n; // number of vertices
vector<bool> visited;
vector<int> ans;
void dfs(int v) {
    visited[v] = true;
    for (int u : arr[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}
void topological_sort() {
    visited.assign(n+1, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
void solve(){
    long long int m,x,y;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        arr[i].clear();
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        arr[x].push_back(y);
    }
    topological_sort();
    long long int t = 0;
    for(int i=1;i<=1010;i++){
        int count = 0;
        for(int j=n-1;j>=0;j--){
            if(val[ans[j]]==0) continue;
            val[ans[j]]--;
            count++;
            for(auto to:arr[ans[j]]){
                val[to]++;
            }
        }
        if(count==0){
            cout<<i-1<<"\n";
            return;
        }
    }
    for(auto i:ans){
        for(auto j:arr[i]){
            val[j] = add(val[j]%mod,val[i]%mod);
        }
    }
    cout<<add(1010,val[ans[n-1]])<<"\n";
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