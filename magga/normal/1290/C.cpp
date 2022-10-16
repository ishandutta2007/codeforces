#include<bits/stdc++.h>
#pragma GCC target ("avx2")
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
pii parent[600001];
int siz[600001];
pii val[600001];
int par[600001]{0};
ll ans = 0;
int curr = 300001;
void make_set(int v) {
    parent[v] = make_pair(v, 0);
    siz[v] = 1;
    val[v] = {1,0};
}
int make_dummy(){
    parent[curr] = {curr,0};
    siz[curr]=0;
    val[curr]={0,0};
    curr++;
    return curr-1;
}
pair<int, int> find_set(int v){
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}
void add_edge(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;
    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;
    if (a == b) {
    }else{
        ans-=min(val[a].F,val[a].S);
        ans-=min(val[b].F,val[b].S);
        if (siz[a] < siz[b])
            swap (a, b);
        if(x==y){
            val[a].S+=val[b].F;
            val[a].F+=val[b].S;
        }else{
            val[a].F+=val[b].F;
            val[a].S+=val[b].S;
        }
        ans+=min(val[a].F,val[a].S);
        parent[b] = make_pair(a, x^y^1);
        if (siz[a] == siz[b])
            siz[a]+=siz[b];
    }
}
void compulsary(int v,bool a){
    auto j = find_set(v);
    ans -= min(val[j.F].F,val[j.F].S);
    if(a!=j.S){
        val[j.F].S=1e9;
    }else{
        val[j.F].F=1e9;
    }
    ans += min(val[j.F].F,val[j.F].S);
}
void pre(){}
void solve(){
    ll n,k;cin>>n>>k;
    for(int i=0;i<=k;i++){
        make_set(i);
    }
    vector<int>arr[n+1];
    ll d,a;
    string s;cin>>s;
    for(int i=0;i<k;i++){
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>d;
            arr[d].push_back(i+1);
        }
    }
    for(int i=1;i<=n;i++){
        if(arr[i].size()==1){
            if(s[i-1]=='0'){
                compulsary(arr[i][0],1);
            }else{
                compulsary(arr[i][0],0);
            }
        }else if(arr[i].size()==2){
            if(s[i-1]=='0'){
                add_edge(arr[i][0],arr[i][1]);
            }else{
                auto c = make_dummy();
                add_edge(c,arr[i][0]);
                add_edge(c,arr[i][1]);
            }
        }
        cout<<ans<<"\n";
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