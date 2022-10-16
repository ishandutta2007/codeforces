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
    long long int n,m;cin>>n>>m;
    set<long long int>arr[n+1];
    for(int i=0;i<=n;i++){
        arr[i].insert(0);
    }
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].insert(v);
        arr[v].insert(u);
    }
    set<int> ans;
    for(int i=1;i<=n;i++){
        if((*arr[i].rbegin())<i){
            ans.insert(i);
        }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int t;cin>>t;
        if(t==3){
            cout<<ans.size()<<"\n";
            continue;
        }
        cin>>u>>v;
        if(t==1){
            arr[u].insert(v);
            arr[v].insert(u);
            if((*arr[u].rbegin())<u) ans.insert(u);
            else if(ans.find(u)!=ans.end()) ans.erase(u); 
            if((*arr[v].rbegin())<v) ans.insert(v);
             else if(ans.find(v)!=ans.end()) ans.erase(v); 
        }else{
            arr[u].erase(v);
            arr[v].erase(u);
             if((*arr[u].rbegin())<u) ans.insert(u);
            else if(ans.find(u)!=ans.end()) ans.erase(u); 
            if((*arr[v].rbegin())<v) ans.insert(v);
             else if(ans.find(v)!=ans.end()) ans.erase(v); 
        }
    }
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