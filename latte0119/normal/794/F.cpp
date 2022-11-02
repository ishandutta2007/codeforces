#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int SEG=1<<17;

int N,Q;
int dat[SEG*2][10];
int put[SEG*2][10];



void init(vint &A){
    rep(i,SEG*2)rep(j,10)put[i][j]=j;

    for(int i=0;i<A.size();i++){
        int d=1;
        while(A[i]){
            dat[i+SEG-1][A[i]%10]+=d;
            A[i]/=10;
            d*=10;
        }
    }
    for(int i=SEG-2;i>=0;i--){
        rep(j,10)dat[i][j]=dat[i*2+1][j]+dat[i*2+2][j];
    }
}
int latte[10];
inline void push(int k){
    memset(latte,0,sizeof(latte));
    rep(i,10)latte[put[k][i]]+=dat[k][i];
    rep(i,10)dat[k][i]=latte[i];

    if(k<SEG-1){
        rep(i,10)put[k*2+1][i]=put[k][put[k*2+1][i]];
        rep(i,10)put[k*2+2][i]=put[k][put[k*2+2][i]];
    }
    rep(i,10)put[k][i]=i;
}

void update(int a,int b,int x,int y,int k=0,int l=0,int r=SEG){
    push(k);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        put[k][x]=y;
        push(k);
        return;
    }
    update(a,b,x,y,k*2+1,l,(l+r)/2);
    update(a,b,x,y,k*2+2,(l+r)/2,r);
    rep(i,10)dat[k][i]=dat[k*2+1][i]+dat[k*2+2][i];
}
int malta[10];
void query(int a,int b,int k=0,int l=0,int r=SEG){
    push(k);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        rep(i,10)malta[i]+=dat[k][i];
        return;
    }
    query(a,b,k*2+1,l,(l+r)/2);query(a,b,k*2+2,(l+r)/2,r);
}

signed main(){
    scanf("%lld%lld",&N,&Q);
    vint A(N);rep(i,N)scanf("%lld",&A[i]);

    init(A);

    rep(i,Q){
        int t;scanf("%lld",&t);
        if(t==1){
            int l,r,x,y;
            scanf("%lld%lld%lld%lld",&l,&r,&x,&y);
            l--;
            update(l,r,x,y);
        }
        else{
            int l,r;
            scanf("%lld%lld",&l,&r);
            l--;
            memset(malta,0,sizeof(malta));
            query(l,r);
            int ans=0;
            rep(j,10)ans+=malta[j]*j;
            printf("%lld\n",ans);
        }
    }
    return 0;
}