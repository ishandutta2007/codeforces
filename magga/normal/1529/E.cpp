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
struct Vertex{
    int left=-1,right=-1; // index of Children
    long long int value=0; 
    long long int lazy = 0;
    bool hai = 0;
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(vector<long long int> &arr,int a,int b,vector<Vertex>&SegTree,int &curr){
        l = a;
        r = b;
        if(l==r){
            value = arr[l];
        }else{
            left=curr;curr++;
            SegTree.push_back(Vertex());
            SegTree[left] = Vertex(arr,a,(a+b)/2,SegTree,curr);
            right=curr;curr++;
            SegTree.push_back(Vertex());
            SegTree[right] = Vertex(arr,(a+b)/2+1,b,SegTree,curr);
            recalculate(SegTree);
        }
    }  
    // To Revaluevate this node after update
    void recalculate(vector<Vertex>&SegTree){
        int ruf = value;
        if(left!=-1){
            ruf = max(SegTree[right].value,SegTree[left].value);
        }
        if(hai){
            value = lazy;
        }else{ 
            value = ruf;
        }
    }
    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        SegTree[right].hai=true;
        SegTree[right].lazy=lazy;
        SegTree[right].recalculate(SegTree);
        SegTree[left].hai=true;
        SegTree[left].lazy=lazy;
        SegTree[left].recalculate(SegTree);
        hai = false;
        lazy = 0;
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            lazy = val;
            hai = true;
            recalculate(SegTree);
        }else if(a>r || b<l){
            return;
        }else{
            if(hai)
                push(SegTree);
            SegTree[left].update(a,b,val,SegTree);
            SegTree[right].update(a,b,val,SegTree);
            recalculate(SegTree);
        }
    }
    long long int query(int a,int b,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            return value;
        }else if(a>r || b<l){
            return 0;
        }else{
            if(hai)
                push(SegTree);
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            return max(i,j);
        }
    }  
};
struct SegmentTree{
    int curr = 1;
    vector<Vertex>SegTree; // For Storing Vertexes
    SegmentTree(vector<ll> &arr){
        SegTree.push_back(Vertex());
        SegTree[0] = Vertex(arr,0,arr.size()-1,SegTree,curr);
    }
    void update(ll a,ll b,ll val){
        //cout<<a<<" "<<b<<" "<<val<<"---\n"; 
        SegTree[0].update(a,b,val,SegTree);
    }
    long long int query(ll a,ll b){
        return SegTree[0].query(a,b,SegTree);
    }
};
vector<int>arr[300011];
vector<int>brr[300011];
ll n,u,v,w;
vector<ll>to_seg;
int euler_points[2][300005];
int curr = 0;
void dfs2(int to,int from){
    to_seg.push_back(0);
    euler_points[0][to] = curr;
    euler_points[1][to] = curr;
    curr++;
    for(auto i:brr[to]){
        if(i!=from){
            dfs2(i,to);
            euler_points[1][to] = curr;
            to_seg.push_back(0);
            curr++;
        }
    }
}
set<ll>s;
ll ans = 0;
vector<ll>test{1};
SegmentTree tree(test);
void dfs(int to,int from){
    int reverse  =  0;
    auto p = tree.query(euler_points[0][to],euler_points[1][to]);
    int k = tree.query(euler_points[0][to],euler_points[0][to]);
    //cout<<k<<" ye wala\n";
    if(p==0){
        reverse = 1;
        s.insert(to);
        tree.update(euler_points[0][to],euler_points[1][to],to);
    }else if(p!=0 && tree.query(euler_points[0][to],euler_points[0][to])!=0){
        k = tree.query(euler_points[0][to],euler_points[0][to]);
        reverse = 2;
        s.erase(k);
        tree.update(euler_points[0][k],euler_points[1][k],0);
        s.insert(to);
        tree.update(euler_points[0][to],euler_points[1][to],to);
    }
    ans = max(ans,ll(s.size()));
    //cout<<to<<" "<<s.size()<<" "<<reverse<<"\n";
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);
        }
    }
    
    if(reverse==1){
        s.erase(to);
        tree.update(euler_points[0][to],euler_points[1][to],0);
    }else if(reverse==2){
        s.erase(to);
        tree.update(euler_points[0][to],euler_points[1][to],0);
        s.insert(k);
        tree.update(euler_points[0][k],euler_points[1][k],k);
    }
}
// Please write the recurances once :(
void pre(){}
void solve(){
    curr = 0;
    ans = 0;
    s.clear();
    to_seg.clear();
    ll n;cin>>n;
    for(int i=0;i<=n;i++){
        arr[i].clear();
        brr[i].clear();
    }
    for(int v=2;v<n+1;v++){
        cin>>u;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int v=2;v<n+1;v++){
        cin>>u;
        brr[u].push_back(v);
        brr[v].push_back(u);
    }   
    dfs2(1,-1);
    tree = *new SegmentTree(to_seg);
    dfs(1,-1);
    cout<<ans<<"\n";
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