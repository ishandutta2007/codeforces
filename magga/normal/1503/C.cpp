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
 // To maintain till where segment tree is filled

struct SegmentTree{
    const long long int N = 1e5;
    long long int n;
    long long int t[200000];
    long long int combine(long long int a,long long int b){
        return min(a,b);
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
        long long int ret = 1e18;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ret=combine(ret,t[l++]);
            if(r&1) ret=combine(t[--r],ret);
        }
        return ret;
    }
    SegmentTree(vector<ll>a){
        n = a.size();
        for(int i=0;i<n;i++){
            t[n+i]=a[i];
        }
        build();
    }
};

// Please write the recurances once :(
void pre(){}
ll helmp(vector<pii>v){
    int n = v.size();
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++){
        a[i]=1e18;
        b[i]=1e18;
    }
    a[n-1]=0;
    b[n-1]=v[n-1].F;
    SegmentTree wai(b);
    SegmentTree woai(a);
    for(int i=n-2;i>=0;i--){
        int start = i,end=n-1,mid,ans=i;
        while(start<=end){
            mid = (start+end+1)/2;
            if(v[mid].F-v[i].F-v[i].S<=0){
                start = mid+1;
                ans = mid;
            }else{
                end = mid-1;
            }
        }
        ll sol = min(woai.query(i,ans+1),wai.query(ans+1,n)-v[i].F-v[i].S);
        woai.modify(i,sol);
        wai.modify(i,sol+v[i].F);
    }
    return woai.query(0,1);
}
void solve(){
    ll n;cin>>n;
    vector<pair<pii,ll>>v(n);
    ll ans = 0;
    for(int i=0;i<n;i++){
        cin>>v[i].F.F>>v[i].F.S;
        v[i].S = i;
        ans+=v[i].F.S;
    }
    sort(v.begin(),v.end());
    int i = 0;
    for(;i<n;i++){
        if(v[i].S==0){
            break;
        }
    }
    i= n;
    vector<pii>a[2];
    for(int j=0;j<n;j++){
        if(j<=i){
            a[0].push_back(v[j].F);
        }
        if(j>=i){
            a[1].push_back(v[j].F);
        }
    }
    //cout<<v[i].S<<" "<<a[0].back().F<<" "<<a[1][0].F<<"\n";
    cout<<ans+helmp(a[0])<<"\n";
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