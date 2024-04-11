#include<bits/stdc++.h>
#pragma GCC target ("avx2")
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
int curr = 1;
struct Vertex{
    int left=-1,right=-1;
    long long int value=0,product=0;
    ll l=0,r=0;
    Vertex(){}
    Vertex(vector<long long int> &arr,int a,int b,vector<Vertex>&SegTree){
        if(a>b){
            return;
        }
        l = a;
        r = b;
        int oo = SegTree.size()-1;
        if(l==r){
            value = arr[l];
            product = arr[l];
        }else{
            left=curr;
            curr++;
            SegTree.push_back(Vertex());
            SegTree[left] = Vertex(arr,a,(a+b)/2,SegTree);
            right=curr;
            curr++;
            SegTree.push_back(Vertex());
            SegTree[right] = Vertex(arr,(a+b)/2+1,b,SegTree);
            product = mul(SegTree[right].product,SegTree[left].product);
            value = add(mul(SegTree[left].value,SegTree[right].product),SegTree[right].value);
        }
    }  
    pii query(int a,int b,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            return {value,product};
        }else if(a>r || b<l){
            return {0,0};
        }else{
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            return {add(mul(i.F,j.S),j.F),mul(i.S,j.S)};
        }
    }  
};
vector<Vertex>SegTree;
void pre(){}
ll val(ll i){
    return mul(100,power(i,mod-2));
}
void solve(){
    ll n,d;cin>>n;
    vector<ll>v;
    for(int i=0;i<n;i++){
        cin>>d;
        v.push_back(val(d));
    }
    SegTree.push_back(Vertex());
    SegTree[0]=Vertex(v,0,n-1,SegTree);
    ll ans = 0;
    ans = SegTree[0].query(0,n-1,SegTree).F;
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}