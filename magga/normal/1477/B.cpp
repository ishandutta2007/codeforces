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
int curr = 1; // To maintain till where segment tree is filled
struct Vertex{
    int left=-1,right=-1; // index of Children
    pii value = {0,0}; 
    pii lazy = {0,0};
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(vector<long long int> &arr,int a,int b,vector<Vertex>&SegTree){
        l = a;
        r = b;
        if(l==r){
            if(arr[l]==1){
                value = {0,1};
            }else{
                value = {1,0};
            }
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
        if(left!=-1){
            if(lazy.F){
                if(lazy.S==1){
                    value = {0,r-l+1};
                }else{
                    value = {r-l+1,0};
                }
            }else{
                value.F = SegTree[right].value.F + SegTree[left].value.F;
                value.S = SegTree[right].value.S + SegTree[left].value.S;
            }
        }else{
            if(lazy.F){
                if(lazy.S==1){
                    value = {0,r-l+1};
                }else{
                    value = {r-l+1,0};
                }
            }
        }
    }
    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        if(lazy.F==1){
            SegTree[right].lazy=lazy;
            SegTree[right].recalculate(SegTree);
            SegTree[left].lazy=lazy;
            SegTree[left].recalculate(SegTree);
        }
        lazy={0,0};
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            lazy={1,val};
            recalculate(SegTree);
        }else if(a>r || b<l){
            return;
        }else{
            SegTree[left].update(a,b,val,SegTree);
            SegTree[right].update(a,b,val,SegTree);
            recalculate(SegTree);
        }
    }
    pii query(int a,int b,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            return value;
        }else if(a>r || b<l){
            return {0,0};
        }else{
            push(SegTree);
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            return {i.F+j.F,i.S+j.S};
        }
    }  
};
struct SegmentTree{
    vector<Vertex>SegTree; // For Storing Vertexes
    SegmentTree(vector<ll> &arr){
        curr=1;
        SegTree.push_back(Vertex());
        SegTree[0] = Vertex(arr,0,arr.size()-1,SegTree);
    }
    void update(ll a,ll b,ll val){
        SegTree[0].update(a,b,val,SegTree);
    }
    pii query(ll a,ll b){
        return SegTree[0].query(a,b,SegTree);
    }
};
void pre(){}
void solve(){
    ll n,q;cin>>n>>q;
    string s,f;cin>>s>>f;
    vector<ll>sv(n);
    vector<ll>fv(n);
    for(int i=0;i<n;i++){
        sv[i]=s[i]-'0';
        fv[i]=f[i]-'0';
    }
    SegmentTree seg(fv);
    ll l,r;
    stack<pii>queries;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        queries.push({l-1,r-1});
    }
    while(queries.size()>0){
        auto i = queries.top();
        queries.pop();
        auto p = seg.query(i.F,i.S);
        if(min(p.F,p.S)>=(i.S-i.F+2)/2){
            cout<<"NO"<<"\n";
            //cout<<i.F<<" "<<i.S<<" :0"<<"\n";
            return;
        }else{
            if(p.F>p.S){
                //cout<<"update "<<i.F<<" "<<i.S<<"\n";
                seg.update(i.F,i.S,0);
            }else{
                seg.update(i.F,i.S,1);
            }
        }
    }
    //cout<<seg.query(3,3).S<<"----\n";
    //cout.flush();
    for(int i=0;i<n;i++){
        //cout<<sv[i]<<" "<<seg.query(i,i).F<<" "<<seg.query(i,i).S<<"\n";
        if( (sv[i]==1 && seg.query(i,i).S!=1) || (sv[i]==0 && seg.query(i,i).F!=1) ){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
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