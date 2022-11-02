#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef bitset<1000>bs;
const int SIZE=100000;
const int SEG=1<<17;

int N,M;
int A[SIZE];
vint G[SIZE];

int tt,tin[SIZE],tout[SIZE],vs[SIZE];
void dfs(int v,int p){
    vs[tt]=v;
    tin[v]=tt++;
    for(int to:G[v])if(to!=p)dfs(to,v);
    tout[v]=tt;
}

bs base,prime;

bs seg[SEG*2];
int put[SEG*2];

void build(){
    rep(i,N)seg[i+SEG-1].set(A[vs[i]]);
    for(int i=SEG-2;i>=0;i--)seg[i]=seg[i*2+1]|seg[i*2+2];
}
inline void push(int k){
    if(put[k]==0)return;
    seg[k]=(seg[k]<<put[k]&base)|(seg[k]>>(M-put[k]));
    if(k<SEG-1){
        (put[k*2+1]+=put[k])%=M;
        (put[k*2+2]+=put[k])%=M;
    }
    put[k]=0;
}
void add(int a,int b,int x,int k=0,int l=0,int r=SEG){
    push(k);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        (put[k]+=x)%=M;
        push(k);
        return;
    }
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
    seg[k]=seg[k*2+1]|seg[k*2+2];
}

bs res;
void get(int a,int b,int k=0,int l=0,int r=SEG){
    push(k);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b)res|=seg[k];
    else{
        get(a,b,k*2+1,l,(l+r)/2);
        get(a,b,k*2+2,(l+r)/2,r);
    }
}
signed main(){
    scanf("%d%d",&N,&M);
    rep(i,N)scanf("%d",&A[i]),A[i]%=M;
    rep(i,N-1){
        int a,b;scanf("%d%d",&a,&b);a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    dfs(0,-1);
    for(int i=2;i<M;i++){
        bool ok=true;
        for(int j=2;j*j<=i;j++){
            ok&=i%j!=0;
        }
        if(ok)prime.set(i);
    }
    rep(i,M)base.set(i);

    build();
    int Q;scanf("%d",&Q);
    while(Q--){
        int type;scanf("%d",&type);
        if(type==1){
            int v,x;
            scanf("%d%d",&v,&x);
            v--;
            add(tin[v],tout[v],x%M);
        }
        else{
            int v;
            scanf("%d",&v);
            v--;
            res.reset();
            get(tin[v],tout[v]);
            printf("%d\n",(res&prime).count());
        }
    }
    return 0;
}