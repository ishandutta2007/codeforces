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
    pii value; 
    long long int lazy=0;
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(int a,int b,vector<Vertex>&SegTree,int &curr){
        l = a;
        r = b;
        if(l==r){
            value = {0,l};
        }else{
            left=curr;curr++;
            SegTree.push_back(Vertex());
            SegTree[left] = Vertex(a,(a+b)/2,SegTree,curr);
            right=curr;curr++;
            SegTree.push_back(Vertex());
            SegTree[right] = Vertex((a+b)/2+1,b,SegTree,curr);
            recalculate(SegTree);
        }
    }  

    pii merge(pii left,pii right){
        if(left.F<=right.F){
            return {left.F+lazy,left.S};
        }else{
            return {right.F+lazy,right.S};
        }
    }

    // To Revaluevate this node after update
    void recalculate(vector<Vertex>&SegTree){
        if(left!=-1)
            // change this
            value = merge(SegTree[left].value,SegTree[right].value);
        else{
            value.F  += lazy;
            lazy = 0;
        }
    }

    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        if(lazy){
            SegTree[right].lazy+=lazy;
            SegTree[right].recalculate(SegTree);
            SegTree[left].lazy+=lazy;
            SegTree[left].recalculate(SegTree);
            lazy=0;
        }   
    }

    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            // change this
            lazy+=val;
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
            return value;
        }else if(a>r || b<l){
            return {1e9,-1};
        }else{
            push(SegTree);
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            return merge(i,j);
        }
    }  
};
struct SegmentTree{
    int curr = 1;
    vector<Vertex>SegTree; // For Storing Vertexes
    SegmentTree(int n){
        SegTree.push_back(Vertex());
        SegTree[0] = Vertex(0,n-1,SegTree,curr);
    }
    void update(ll a,ll b,ll val){
        SegTree[0].update(a,b,val,SegTree);
    }
    pii query(ll a,ll b){
        return SegTree[0].query(a,b,SegTree);
    }
};

struct SegmentTee{
    long long int n;
    vector<pii>t;
    pii combine(pii a,pii b){
        if(a.F<=b.F){
            return a;
        }else{
            return b;
        }
    }
    void build(){
        for(long long int i=n-1;i>0;i--){
            t[i]=combine(t[i<<1],t[i<<1|1]);
        }
    }
    void modify(long long int p,long long int value){
        for(t[p+=n].F=value;p>1;p>>=1){
            t[p>>1]=combine(t[p],t[p^1]);
        } 
    }
    pii query(long long int l,long long int r){
        pii ret = {1e9,0};
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ret=combine(ret,t[l++]);
            if(r&1) ret=combine(t[--r],ret);
        }
        return ret;
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int n;cin>>n;
    pii arr[n];
    priority_queue<pii>pq;
    for(int i=0;i<n;i++){
        cin>>arr[i].F;
        arr[i].S = i;
        pq.push(arr[i]);
    }
    SegmentTee segs;
    SegmentTree segs2(n);
    segs.t.resize(2*n);
    segs.n = n;
    for(int i=0;i<n;i++) segs.t[n+i] = arr[i];
    segs.build();
    ll ans = 0;
    vector<bool>flag(n,1);
    while(pq.size()>0){
        auto i = pq.top();
        pq.pop();
        pii nextIndice = segs2.query(i.S,n-1);
        if(nextIndice.F!=0) break;
        auto t = segs.query(0,nextIndice.S);
        if(t.F < i.F){
            ans+=i.F - t.F;
            flag[i.S] = 1;
            flag[t.S] = 1;
            segs.modify(i.S,1e9);
            segs.modify(t.S,1e9);
            segs2.update(i.S,n-1,-1);
            segs2.update(t.S,n-1,1);
        }else{
            flag[i.S] = 1;
            segs.modify(i.S,1e9);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();  
}