#include<bits/stdc++.h>
using namespace std;
void pre(){}
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
    }
}
vector<int>arr[300001];
pair<int,int> dfs(int to,int from){
    int val = 0;
    int oo = to;
    for(int i:arr[to]){
        if(i!=from){
            auto j = dfs(i,to);
            if(val<j.first+1){
                val=j.first+1;
                oo=j.second;
            }
        }
    }
    return {val,oo};
}
void solve(){
    int n,m,q,u,v;cin>>n>>m>>q;
    for(int i=1;i<=n;i++) make_set(i);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        union_sets(u,v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int i=1;i<=n;i++) val[i]=-1;
    for(int i=1;i<=n;i++){
        if(val[find_set(i)]==-1){
            auto m = dfs(i,0);
            auto j = dfs(m.second,0);
            val[find_set(i)]=j.first;
        }
    }
    for(int i=0;i<q;i++){
        char c;
        cin>>c;
        if(c=='1'){
            int a;cin>>a;
            cout<<val[ find_set(a) ]<<"\n";
        }else{
            int a,b;cin>>a>>b;
            if(find_set(a)==find_set(b)){
                continue;
            }
            int o1 = val[find_set(a)];
            int o2 = val[find_set(b)];
            if(o1<o2){
                int temp = o2;
                o2=o1;
                o1=temp;
            }
            int vl = max((o1+1)/2+(o2+1)/2+1,o1);
            union_sets(a,b);
            val[find_set(a)]=vl;
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