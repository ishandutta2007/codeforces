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
ll lazy_state[4][4] = {{0,1,2,3},{1,0,2,3},{2,3,2,3},{3,2,2,3}};
int curr = 1; // To maintain till where segment tree is filled
struct Vertex{
    int left=-1,right=-1; // index of Children
    pair<long long int,long long int>value; 
    int lazy = 0;
    pair<long long int,long long int>og;
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(vector<pii> &arr,int a,int b,vector<Vertex>&SegTree){
        l = a;
        r = b;
        if(l==r){
            value = arr[l];
            og = value;
        }else{
            left=curr;curr++;
            SegTree.push_back(Vertex());
            SegTree[left] = Vertex(arr,a,(a+b)/2,SegTree);
            right=curr;curr++;
            SegTree.push_back(Vertex());
            SegTree[right] = Vertex(arr,(a+b)/2+1,b,SegTree);
            recalculate(SegTree);
        }
    }  
    // To Revaluevate this node after update
    void recalculate(vector<Vertex>&SegTree){
        if(left!=-1)
            value = {SegTree[right].value.F+SegTree[left].value.F,SegTree[right].value.S+SegTree[left].value.S};
        else{
            value = og;
        }
        if(lazy == 1){
            swap(value.F,value.S);
        }else if(lazy == 2){
            value.F+=value.S;
            value.S = 0;
        }else if(lazy==3){
            value.S+=value.F;
            value.S = 0;
        }
    }
    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        if(lazy==0){
            return;
        }
        SegTree[right].lazy=lazy_state[SegTree[right].lazy][lazy];
        SegTree[right].recalculate(SegTree);
        SegTree[left].lazy=lazy_state[SegTree[left].lazy][lazy];
        SegTree[left].recalculate(SegTree);
        lazy=0;
    }
    // Lazy update over a range
    void update(int a,int b,int val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            lazy=lazy_state[lazy][val];
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
    void global_push(vector<Vertex>&SegTree){
        if(left==-1){
            return;
        }else{
            push(SegTree);  
            SegTree[left].global_push(SegTree);
            SegTree[right].global_push(SegTree);
        }
    } 
};
struct SegmentTree{
    vector<Vertex>SegTree; // For Storing Vertexes
    SegmentTree(vector<pii> &arr){
        SegTree.push_back(Vertex());
        SegTree[0] = Vertex(arr,0,arr.size()-1,SegTree);
    }
    void global_push(){
        SegTree[0].global_push(SegTree);
    }
    void update(int a,int b,int val){
        SegTree[0].update(a,b,val,SegTree);
    }
    vector<int> query(){
        vector<int>arr(1e5+1);
        for(int i=0;i<SegTree.size();i++){
            if(SegTree[i].l==SegTree[i].r){
                arr[SegTree[i].l] = SegTree[i].lazy;
            }
        }
        return arr;
    }
};
void pre(){}
void solve(){
    long long int n,d,q;
    cin>>n>>q;
    vector<pii>arr(1e5+1);
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>d;
        a[i] = d;
        if(d<0){
            arr[-1*d].S++;
        }else{
            arr[d].F++;
        }
    }
    SegmentTree s(arr);
    char c;
    for(int i=0;i<q;i++){
        cin>>c>>d;
        if(c=='<'){
            if(d<=0){
                d--;
                d*=-1;
                s.update(d,1e5,2);
            }else{
                d--;
                s.update(d+1,1e5,2);
                s.update(0,d,1);
            }
        }else{
            if(d>=0){
                s.update(d+1,1e5,3);
            }else{
                d*=-1;
                s.update(d,1e5,3);
                s.update(0,d-1,1);
            } 
        }
        //s.global_push();
    }
    s.global_push();
    auto b = s.query();
    for(int i=0;i<n;i++){
        //cout<<a[i]<<" "<<b[abs(a[i])]<<"\n";
        if( (  a[i]>0 && (b[abs(a[i])]==0 || b[abs(a[i])]==2)) || (a[i]<0 && (b[abs(a[i])]==0 || b[abs(a[i])]==3) )){
            cout<<a[i]<<" ";
        }else{
            cout<<-1*a[i]<<" ";
        }
    }
    cout<<"\n";
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