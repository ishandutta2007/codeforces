#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
typedef long long ll;
using namespace std;
int parent[300001];
int siz[300001];
pair<int,int> val[300001];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
    val[v]={v,v};
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
void pre(){}
void solve(){
    ll n;cin>>n;
    ll u,v,a,b;
    for(int i=1;i<=n;i++)
        make_set(i);
    int arr[150001]{0};
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        a = find_set(u);
        b = find_set(v);
        union_sets(a,b);
        arr[val[a].second]=val[b].first;
        //cout<<val[a].second<<" "<<val[b].first<<"\n";
        val[find_set(a)]={val[a].first,val[b].second};
    }
    a = val[find_set(1)].first;
    while(a!=0){
        cout<<a<<" ";
        a = arr[a];
    }
    cout<<"\n";
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