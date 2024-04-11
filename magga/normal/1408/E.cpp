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
typedef  pair<long long int,long long int> iPair;  
struct Graph{ 
    long long int V, E; 
    vector< pair<long long int, iPair> > edges; 
    Graph(int V, int E){ 
        this->V = V; 
        this->E = E; 
    }  
    void addEdge(int u, int v,long long int w){ 
        edges.push_back({w, {u, v}}); 
    } 
    long long int kruskalMST(); 
}; 
struct DisjointSets{ 
    long long int *parent, *rnk; 
    long long int n;  
    DisjointSets(long long int n){ 
        this->n = n; 
        parent = new long long int[n+1]; 
        rnk = new long long int[n+1]; 
        for (int i = 0; i <= n; i++){ 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
    long long int find(long long int u){ 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
    void merge(long long int x,long long int y){ 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else 
            parent[x] = y; 
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
long long int Graph::kruskalMST(){ 
    long long int mst_wt = 0;
    sort(edges.begin(), edges.end()); 
    DisjointSets ds(V); 
    vector< pair<long long int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++){ 
        long long int u = it->second.first; 
        long long int v = it->second.second; 
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
        if (set_u != set_v){ 
            mst_wt += it->first;  
            ds.merge(set_u, set_v); 
        } 
    } 
    return mst_wt; 
} 
void solve(){
    int n,m,d,sum = 0,k;cin>>m>>n;
    long long int a[m];
    long long int b[n];
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int>arr[m];
    for(int i=0;i<m;i++){
        cin>>d;
        sum+=d;
        for(int j=0;j<d;j++){
            cin>>k;
            k--;
            arr[i].push_back(k);
        }
    }
    Graph g(n+m,sum);
    long long int ans = 0;
    for(int i=0;i<m;i++){
        for(auto j:arr[i]){
            g.addEdge(n+i,j,-1*(a[i]+b[j]));
            ans += a[i] + b[j]; 
        }
    }
    cout<<ans + g.kruskalMST()<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}