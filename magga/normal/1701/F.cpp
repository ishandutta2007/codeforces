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
struct sug{
    long long int n;
    vector<long long int>t;
    sug(){
        n = 201001;
        t.assign(n*2+10,0);
    }
    long long int combine(long long int a,long long int b){
        return a+b;
    }
    void build(){
        for(long long int i=n-1;i>0;i--){
            t[i]=combine(t[i<<1],t[i<<1|1]);
        }
    }
    void modify(long long int p,long long int value){
        for(t[p+=n]=value;p>1;p>>=1){
            t[p>>1]=combine(t[p],t[p^1]);
        } 
    }
    long long int query(long long int l,long long int r){
        long long int ret = 0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ret=combine(ret,t[l++]);
            if(r&1) ret=combine(t[--r],ret);
        }
        return ret;
    }
};
struct Vertex{
    int left=-1,right=-1; // index of Children
    long long int active = 0;
    long long int sHigh = 0;
    long long int sum = 0; 
    long long int lazy = 0;
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(int a,int b,vector<Vertex>&SegTree,int &curr){
        l = a;
        r = b;
        if(l==r){
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

    // To Revaluevate this node after update
    void recalculate(vector<Vertex>&SegTree){
        if(left!=-1){
            active = SegTree[left].active + SegTree[right].active;
            sHigh =  SegTree[left].sHigh + SegTree[right].sHigh;
            sum   =  SegTree[left].sum + SegTree[right].sum;
            sum   += sHigh*lazy + ((lazy*(lazy - 1))/2)*active;
            sHigh += active*lazy;
        }else{
            sum   += sHigh*lazy + ((lazy*(lazy - 1))/2)*active;
            sHigh += active*lazy;
            lazy = 0;  
        }
    }

    void push(vector<Vertex>&SegTree){
        if(lazy!=0){
            if(SegTree[right].active>0){
                SegTree[right].lazy+=lazy;
                SegTree[right].recalculate(SegTree);
            }
            if(SegTree[left].active>0){
                SegTree[left].lazy+=lazy;
                SegTree[left].recalculate(SegTree);
            }
            lazy=0;
        }
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            if(active>0){
                lazy+=val;
                recalculate(SegTree);
            }
        }else if(a>r || b<l){
            return;
        }else{
            push(SegTree);
            SegTree[left].update(a,b,val,SegTree);
            SegTree[right].update(a,b,val,SegTree);
            recalculate(SegTree);
        }
    }

    void set(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            if(val==-1){
                active = 0;
                lazy   = 0;
                sum    = 0;
                sHigh  = 0;
            }else{
                active = 1;
                lazy   = 0;
                sum    = (val*(val-1))/2;
                sHigh  = val;
            }
        }else if(a>r || b<l){
            return;
        }else{
            push(SegTree);
            SegTree[left].set(a,b,val,SegTree);
            SegTree[right].set(a,b,val,SegTree);
            recalculate(SegTree);
        }
    }

    long long int query(vector<Vertex>&SegTree){
        return sum;
    } 
};
struct SegmentTree{
    int curr = 1;
    vector<Vertex>SegTree; // For Storing Vertexes
    SegmentTree(int n){
        SegTree.push_back(Vertex());
        SegTree[0] = Vertex(0,n,SegTree,curr);
    }
    void update(ll a,ll b,ll val){
        SegTree[0].update(a,b,val,SegTree);
    }
    void set(ll a,ll val){
        SegTree[0].set(a,a,val,SegTree);
    }
    long long int query(){
        return SegTree[0].query(SegTree);
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int q,d;cin>>q>>d;
    set<int>s;
    sug st;
    SegmentTree segs(200001);
    for(int i=0;i<q;i++){
        int t;cin>>t;
        if(s.find(t)==s.end()){
            s.insert(t);
            int val = st.query(t+1,min(t+d+1,200001));
            st.modify(t,1);
            segs.set(t,val);
            if(t!=1)
                segs.update(max(1,t-d),t-1,1);
        }else{
            s.erase(t);
            st.modify(t,0);
            segs.set(t,-1);
            if(t!=1)
                segs.update(max(1,t-d),t-1,-1);
        }
        cout<<segs.query()<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();   
}