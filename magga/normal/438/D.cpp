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
const long long int N = 1e5+1;
struct node{
    ll sum,max,index;
};
long long int n;
struct node t[2*N];
struct node combine(struct node &a,struct node &b){
    struct node ret{a.sum+b.sum,max(a.max,b.max),0};
    if(a.max>b.max){
        ret.index=a.index;
    }else{
        ret.index=b.index;
    }
    return ret;
}
void build(){
    for(long long int i=n-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(long long int p,long long int value){
    t[p+n].sum = value;
    t[p+n].max = value;
    t[p+n].index = p;
    p+=n;
    for(;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
long long int query(long long int l,long long int r){
    long long int ret = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ret+=t[l++].sum;
        if(r&1) ret+=t[--r].sum;
    }
    return ret;
}
struct node qm(long long int l,long long int r){
    struct node ret = {0,0,0};
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,t[l++]);
        if(r&1) ret=combine(ret,t[--r]);
    }
    return ret;
}
void rem(ll l,ll r,ll x){
    while(true){
        auto i = qm(l,r);
        //cout<<i.index<<" "<<i.max<<" "<<t[n+i.index].index<<"--\n";
        if(t[n+i.index].max>=x){
            modify(i.index,t[n+i.index].max%x);
        }else{
            break;
        }
    }
}
void pre(){}
void solve(){
    ll q,a,b,c,d;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>t[n+i].sum;
        t[n+i].max=t[n+i].sum;
        t[n+i].index=i;
    }
    build();
    for(int i=0;i<q;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            cout<<query(b-1,c)<<"\n";
        }else if(a==2){
            cin>>b>>c>>d;
            rem(b-1,c,d);
        }else{
            cin>>b>>c;
            modify(b-1,c);
        }
    }
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