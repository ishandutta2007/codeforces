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
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
int curr = 1; // To maintain till where segment tree is filled
struct Vertex{
    int left=-1,right=-1; // index of Children
    long long int value=0; 
    long long int lazy = 0;
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(vector<long long int> &arr,int a,int b,vector<Vertex>&SegTree){
        l = a;
        r = b;
        if(l==r){
            value = arr[l];
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
            value = SegTree[right].value+SegTree[left].value+(r-l+1)*lazy;
        else{
            value = value+lazy;
            lazy = 0;
        }
    }
    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        SegTree[right].lazy+=lazy;
        SegTree[right].recalculate(SegTree);
        SegTree[left].lazy+=lazy;
        SegTree[left].recalculate(SegTree);
        lazy=0;
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
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
    long long int query(int a,int b,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            return value;
        }else if(a>r || b<l){
            return 0;
        }else{
            push(SegTree);
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            return i + j;
        }
    }  
};
struct SegmentTree{
    vector<Vertex>SegTree; // For Storing Vertexes
    SegmentTree(vector<ll> &arr){
        SegTree.push_back(Vertex());
        SegTree[0] = Vertex(arr,0,arr.size()-1,SegTree);
    }
    void update(ll a,ll b,ll val){
        SegTree[0].update(a,b,val,SegTree);
    }
    long long int query(ll a,ll b){
        return SegTree[0].query(a,b,SegTree);
    }
    void set(ll a,ll val){
        auto i = query(a,a);
        auto change = val - i ;
        if(change<0) 
            update(a,a,change);
    }
};
void pre(){}
void solve(){
    ll n;cin>>n;
    ll arr[n];
    ll cost[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    ll m;cin>>m;
    ll brr[m];
    map<int,int>dat;
    for(int i=0;i<m;i++){
        cin>>brr[i];
        dat[brr[i]]=i+1;
    }
    vector<ll>dp(m+1);
    for(int i=1;i<=m;i++){
        dp[i] = 2e17;
    }
    SegmentTree s(dp);
    for(int i=0;i<n;i++){
        int oo = -1;
        ll val;
        if(dat.find(arr[i])!=dat.end()){
            oo = dat[arr[i]];
            val = s.query(oo-1,oo-1);
        }
        if(cost[i]<0){
            s.update(0,m,cost[i]);
        }else{
            int start = 0,end=m-1,mid,ans=0;
            while(start<=end){
                mid = (start+end+1)/2;
                if(brr[mid]>=arr[i]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                    ans = mid + 1;
                }
            }
            s.update(0,ans,cost[i]);
        }
        if(oo!=-1){
            s.set(oo,val);
        }
    }
    if(s.query(m,m)>=1e16){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    cout<<s.query(m,m)<<"\n";
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