#include<bits/stdc++.h>
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

struct Vertex{
    int left=-1,right=-1; // index of Children
    pair<ll,pii>value;
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(vector<long long int> &arr,int a,int b,vector<Vertex>&SegTree,int &curr){
        l = a;
        r = b;
        if(l==r){
            value = {arr[l],{arr[l],arr[l]}};
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

    pair<ll,pii> merge(pair<ll,pii>a,pair<ll,pii>b){
        return {max(a.F+b.F,(ll)-1e17),{max(a.S.F,a.F+b.S.F),max(b.S.S,b.F+a.S.S)}};
    }
    // To Revaluevate this node after update
    void recalculate(vector<Vertex>&SegTree){
        if(left!=-1)
            value = merge(SegTree[left].value,SegTree[right].value);
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            value = {val,{val,val}};
            recalculate(SegTree);
        }else if(a>r || b<l){
            return;
        }else{
            SegTree[left].update(a,b,val,SegTree);
            SegTree[right].update(a,b,val,SegTree);
            recalculate(SegTree);
        }
    }
    pair<ll,pii> query(int a,int b,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            return value;
        }else if(a>r || b<l){
            return {0,{0,0}};
        }else{
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            return merge(i,j);
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
    void update(ll a,ll val){
        SegTree[0].update(a,a,val,SegTree);
    }
    pair<ll,pii> query(ll a,ll b){
        return SegTree[0].query(a,b,SegTree);
    }
};

void solve(){
    int n;cin>>n;
    vector<ll>arr(n);
    priority_queue<pii>pq;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pq.push({arr[i],i});
    }
    SegmentTree segs(arr);
    while(pq.size()>0){
        auto i = pq.top();
        pq.pop();
        auto back = segs.query(0,i.S-1);
        auto front = segs.query(i.S+1,n-1);
        if(back.S.S>0 || front.S.F>0){
            cout<<"NO"<<"\n";
            return;
        }
        segs.update(i.S,-1e16);
    }
    cout<<"YES"<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    for(long long int i=0;i<T;i++){
        solve();
    }   
}