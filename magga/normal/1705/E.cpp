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

struct Vertex{
    int left=-1,right=-1; // index of Children
    long long int value=0; 
    bool set = false;
    pii nearest;
    long long int lazy=0;
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(vector<long long int> &arr,int a,int b,vector<Vertex>&SegTree,int &curr){
        l = a;
        r = b;
        if(l==r){
            if(arr[l]==1){
                nearest = {INF,l};
            }else{
                nearest = {l,INF};
            }
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

    void recalculate(vector<Vertex>&SegTree){
        if(left!=-1)
            if(set){
                if(lazy){
                    nearest = {INF,l};
                }else{
                    nearest = {l,INF};
                }
            }else{
                nearest = {min(SegTree[left].nearest.F,SegTree[right].nearest.F),min(SegTree[left].nearest.S,SegTree[right].nearest.S)};
            }
        else{
            if(set){
                if(lazy){
                    nearest = {INF,l};
                }else{
                    nearest = {l,INF};
                }
                set = false;
            }
        }
    }

    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        if(set){
            SegTree[right].lazy=lazy;
            SegTree[right].set=set;
            SegTree[right].recalculate(SegTree);
            SegTree[left].lazy=lazy;
            SegTree[left].set=set;
            SegTree[left].recalculate(SegTree);
            set = false;
        }
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            set = true;
            lazy = val;
            recalculate(SegTree);
        }else if(a>r || b<l){
            return;
        }else{
            push(SegTree);
            SegTree[left].update(a,b,val,SegTree);
            SegTree[right].update(a,b,val,SegTree);
            recalculate(SegTree);
        }
    }

    pii query(int a,int b,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            return nearest;
        }else if(a>r || b<l){
            return {INF,INF};
        }else{
            push(SegTree);
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            return {min(i.F,j.F),min(i.S,j.S)};
        }
    }  

    int Query(vector<Vertex>&SegTree){
        if(l==r){
            return l;
        }else{
            push(SegTree);
            if(SegTree[right].nearest.S!=INF){
                return SegTree[right].Query(SegTree);
            }else{
                return SegTree[left].Query(SegTree);
            }
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
        if(a<=b)
            SegTree[0].update(a,b,val,SegTree);
    }
    pii query(ll a,ll b){
        return SegTree[0].query(a,b,SegTree);
    }
    void remove(int a){
        auto p = query(a,300000);
        update(a,p.S-1,1);
        update(p.S,p.S,0);
    }
    void add(int a){
        auto p = query(a,300000);
        update(a,p.F-1,0);
        update(p.F,p.F,1);
    }
    long long int ans(){
        return SegTree[0].Query(SegTree);
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int n,q,d;cin>>n>>q;
    vector<long long int>v(300001);
    ll arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
        v[arr[i+1]]++;
    }
    for(int i=0;i<300000;i++){
        v[i+1]+=(v[i]>>1);
        v[i]&=1;
    }
    SegmentTree seg(v);
    for(int i=0;i<q;i++){
        int k,l;cin>>k>>l;
        seg.remove(arr[k]);
        arr[k] = l;
        seg.add(arr[k]);
        cout<<seg.ans()<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); 
}