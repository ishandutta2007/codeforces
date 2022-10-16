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
    long long int lazy=0;
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
        if(left!=-1)
            // change this
            value = SegTree[right].value+SegTree[left].value+(r-l+1)*lazy;
        else{
            // change this
            value = value+lazy;
            lazy = 0;
        }
    }

    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        // change this
        SegTree[right].lazy+=lazy;
        SegTree[right].recalculate(SegTree);
        // change this
        SegTree[left].lazy+=lazy;
        SegTree[left].recalculate(SegTree);
        lazy=0;
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            // change this
            lazy+=val;
            recalculate(SegTree);
        }else if(a>r || b<l){
            return;
        }else{
            SegTree[left].update(a,b,val,SegTree);
            SegTree[right].update(a,b,val,SegTree);
            recalculate(SegTree);
        }
    }
    long long int query2(vector<Vertex>&SegTree,ll k){
        if(value<k) return 1e9;
        if(l==r) return l;
        if(lazy)
            push(SegTree);
        if(SegTree[left].value >= k){
            return SegTree[left].query2(SegTree,k);
        }else{
            return SegTree[right].query2(SegTree,k-SegTree[left].value);
        }
    }  
    
    long long int query(int a,int b,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            return value;
        }else if(a>r || b<l){
            return 0;
        }else{
            if(lazy){
                push(SegTree);
            }
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            
            //change this
            return i + j;
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
        SegTree[0].update(a,b,val,SegTree);
    }
    ll query(ll a,ll b){
        return SegTree[0].query(a,b,SegTree);
    }
    ll query2(ll k){
        return SegTree[0].query2(SegTree,k);
    }
};

// Please write the recurances once :(
void pre(){}
void solve(){
    ll n,k;cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    reverse(arr,arr+n);
    int current = 0;
    vector<ll>to_seg(4e5+10,0);
    to_seg[0]= 1;
    SegmentTree abstractor(to_seg);
    ll ans = 1e9;
    ll curr = 0;
    for(int i=0;i<n;i++){
        while(curr < 4e6 && abstractor.query(curr,curr)==0){
            curr++;
        }
        ll nxt_end = curr+arr[i]/2+1;
        abstractor.update(curr,curr,-1);
        abstractor.update(curr+2,curr+1+(arr[i]-1)/2,2);
        if(arr[i]%2==0) abstractor.update(nxt_end,nxt_end,1);
        ans = min(ans,abstractor.query2(k));
    }
    if(ans == 1e9) ans = -1;
    cout<<ans<<"\n";
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