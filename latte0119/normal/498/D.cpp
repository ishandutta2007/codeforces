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

int dat[SEG*2][60];

int N;
int A[SEG];

void init(int k=0,int l=0,int r=SEG){
    if(l+1==r){
        rep(i,60){
            dat[k][i]=1+(i%A[l]==0);
        }
        return;
    }

    init(k*2+1,l,(l+r)/2);
    init(k*2+2,(l+r)/2,r);

    rep(i,60)dat[k][i]=dat[k*2+1][i]+dat[k*2+2][(i+dat[k*2+1][i])%60];
}

int T;

void update(int k,int x){
    k+=SEG-1;
    rep(i,60)dat[k][i]=1+(i%x==0);

    while(k){
        k=(k-1)/2;
        rep(i,60)dat[k][i]=dat[k*2+1][i]+dat[k*2+2][(i+dat[k*2+1][i])%60];
    }
}


void calc(int a,int b,int k=0,int l=0,int r=SEG){
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        T+=dat[k][T%60];
        return;
    }

    calc(a,b,k*2+1,l,(l+r)/2);
    calc(a,b,k*2+2,(l+r)/2,r);
}

signed main(){
    scanf("%lld",&N);
    fill_n(A,SEG,2);
    rep(i,N)scanf("%lld",&A[i]);

    init();

    int Q;scanf("%lld",&Q);
    while(Q--){
        char c;
        int x,y;
        scanf(" %c%lld%lld",&c,&x,&y);
        if(c=='A'){
            x--;y--;
            T=0;
            calc(x,y);
            printf("%lld\n",T);
        }
        else{
           x--;
           update(x,y);
        }
    }
    return 0;
}