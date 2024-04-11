#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
const long long int mod = 998244353;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}
// Please write the recurances once :(
ll fact[200010];

struct Vertex{
    int left=-1,right=-1; // index of Children
    long long int value=0; 
    long long int lazy=1;
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
            value = mul(add(SegTree[right].value,SegTree[left].value),lazy);
        else{
            // change this
            value = mul(value,lazy);
            lazy = 1;
        }
    }

    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        // change this
        SegTree[right].lazy=mul(SegTree[right].lazy,lazy);
        SegTree[right].recalculate(SegTree);
        // change this
        SegTree[left].lazy=mul(SegTree[left].lazy,lazy);
        SegTree[left].recalculate(SegTree);
        lazy=1;
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            // change this
            lazy=mul(lazy,val);
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
            if(lazy != 1) push(SegTree);
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            //change this
            return add(i,j);
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
};



void pre(){
    fact[0]=1;
    for(int i=1;i<200010;i++) fact[i] = mul(fact[i-1],i);
}
void solve(){
    ll n,m;cin>>n>>m;
    ll ss[n],ts[m];
    vector<ll>count(200001),pount(200001);
    for(int i=0;i<n;i++){
        cin>>ss[i];
        count[ss[i]]++;
        pount[ss[i]]++;
    }
    ll c = fact[n-1];
    for(auto i:count) c = divi(c,fact[i]);
    for(auto &i:count) i = mul(c,i);
    for(int i=0;i<m;i++) cin>>ts[i];
    SegmentTree abstraction(count);
    ll is_equal = 1;
    ll ans = 0;
    for(int i=0;i<min(n,m);i++){
        ans = add(ans,abstraction.query(0,ts[i]-1)*is_equal);
        //cout<<ans<<" "<<is_equal<<" "<<abstraction.query(0,ts[i]-1)<<"\n";
        pount[ts[i]]--;
        if(pount[ts[i]]<0) is_equal = 0;
        if(is_equal){
            abstraction.update(ts[i],ts[i],divi(pount[ts[i]],pount[ts[i]]+1)); 
            abstraction.update(0,200000,mul(pount[ts[i]]+1,divi(1,n-i-1)));
        }
    }
    if(is_equal && m>n) ans = add(ans,1);
    cout<<ans<<"\n";
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