#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

int extra = 0;
int parent[300001];
int siz[300001];
int val[300001];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }else{
        extra++;
    }
}

// Please write the recurances once :(
void pre(){}
void solve(){
    int n,d,a,b;cin>>n>>d;
    for(int i=1;i<=n;i++) make_set(i);
    for(int i=0;i<d;i++){
        cin>>a>>b;
        union_sets(a,b);
        int ans = 0;
        set<pii>ref;
        for(int i=1;i<=n;i++){
            ref.insert({-1*siz[find_set(i)],find_set(i)});
        }
        for(int i=0;i<extra+1;i++){
            auto j = *ref.begin();
            ref.erase(ref.begin());
            ans += -1*j.F;
        }
        cout<<ans-1<<"\n";
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