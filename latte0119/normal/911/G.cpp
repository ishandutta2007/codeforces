#include<bits/stdc++.h>
using namespace std;

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

const int SEG=1<<18;

int N;
int A[222222];

char put[SEG*2][100];

inline void push(int k){
    if(k<SEG-1){
        rep(i,100){
            put[k*2+1][i]=put[k][put[k*2+1][i]];
            put[k*2+2][i]=put[k][put[k*2+2][i]];
        }
    }
    rep(i,100)put[k][i]=i;
}

void update(int a,int b,int x,int y,int k=0,int l=0,int r=SEG){
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        rep(i,100)if(put[k][i]==x)put[k][i]=y;
        return;
    }
    push(k);
    update(a,b,x,y,k*2+1,l,(l+r)/2);
    update(a,b,x,y,k*2+2,(l+r)/2,r);
}


signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%d",&A[i]),A[i]--;

    rep(i,SEG*2)rep(j,100)put[i][j]=j;
    int Q;scanf("%lld",&Q);
    while(Q--){
        int l,r,x,y;
        scanf("%d%d%d%d",&l,&r,&x,&y);
        x--;y--;l--;
        update(l,r,x,y);
    }

    rep(i,SEG-1)push(i);
    rep(i,N){
        if(i)printf(" ");
        printf("%d",put[i+SEG-1][A[i]]+1);
    }puts("");
    return 0;
}