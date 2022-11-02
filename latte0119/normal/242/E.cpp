#include<bits/stdc++.h>
using namespace std;

#define int long long
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

int N;
int A[111111];

const int SEG=1<<17;
int seg[SEG*2][20];
int put[SEG*2];
void init(){
    rep(i,N){
        rep(j,20)seg[i+SEG-1][j]=A[i]>>j&1;
    }
    for(int i=SEG-2;i>=0;i--)rep(j,20)seg[i][j]=seg[i*2+1][j]+seg[i*2+2][j];
}

inline void push(int k,int l,int r){
    rep(i,20)if(put[k]>>i&1)seg[k][i]=r-l-seg[k][i];
    if(k<SEG-1){
        put[k*2+1]^=put[k];
        put[k*2+2]^=put[k];
    }
    put[k]=0;
}

void update(int a,int b,int x,int k=0,int l=0,int r=SEG){
    push(k,l,r);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        put[k]^=x;
        push(k,l,r);
        return;
    }
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
    rep(i,20)seg[k][i]=seg[k*2+1][i]+seg[k*2+2][i];
}
int get(int a,int b,int k=0,int l=0,int r=SEG){
    push(k,l,r);
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b){
        int ret=0;
        rep(i,20)ret+=(1<<i)*seg[k][i];
        return ret;
    }
    return get(a,b,k*2+1,l,(l+r)/2)+get(a,b,k*2+2,(l+r)/2,r);
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    init();
    int M;
    scanf("%lld",&M);
    while(M--){
        int type,l,r;
        scanf("%lld%lld%lld",&type,&l,&r);
        l--;
        if(type==1){
            printf("%lld\n",get(l,r));
        }
        else{
            int x;
            scanf("%lld",&x);
            update(l,r,x);
        }
    }
    return 0;
}