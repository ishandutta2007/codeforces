#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
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

const long long int N = 1e6+1;
long long int n;
long long int t[2*N]{0};
long long int combine(long long int &a,long long int &b){
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
void pre(){}
ll k,d;
void solve(){ 
    cin>>n>>k;
    ll arr[n];
    bool flag[n];
    for(int i=0;i<n;i++){
        cin>>d;
        flag[i]=0;d--;
        arr[d]=i;
    }
    for(int i=0;i<k;i++){
        cin>>d;d--;
        flag[d]=1;
    }   
    build();
    set<int>s;
    s.insert(n);
    s.insert(-1);
    ll ans = 0;
    ll b,c;
    for(int i=0;i<n;i++){
        if(!flag[i]){
            auto p = s.lower_bound(arr[i]);
            b = *p;
            p--;
            c=*p;
           // cout<<b<<" "<<arr[i]<<" "<<c<<"\n";
            ans+=b-c-1+query(c+1,b);
            modify(arr[i],-1);
            //cout<<query(b+1,c)<<"\n";
        }else{
            s.insert(arr[i]);
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