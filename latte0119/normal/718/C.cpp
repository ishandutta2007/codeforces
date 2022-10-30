#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;
int A[55][2][2];

int F(int n){
    int a=1,b=0;
    for(int i=0;n;i++){
        if(n&1){
            int aa=A[i][0][0]*a+A[i][0][1]*b;
            int bb=A[i][1][0]*a+A[i][1][1]*b;
            a=aa%mod;
            b=bb%mod;
        }
        n>>=1;
    }
    return b;
}

struct segtree{
    static const int SEG=1<<17;
    vint dat1,dat2,put1,put2;
    segtree():dat1(SEG*2,1),dat2(SEG*2),put1(SEG*2),put2(SEG*2,1){}

    inline void push(int k){
        if(put1[k]==0&&put2[k]==1)return;
        int d0=(dat2[k]-dat1[k]+mod)%mod;

        int d2=(dat1[k]*put1[k]+dat2[k]*put2[k])%mod;
        int d1=(d0*put1[k]+dat1[k]*put2[k])%mod;
        dat1[k]=d1;
        dat2[k]=d2;

        if(k<SEG-1){
            int p0,p1,p2;

            p0=(put2[k*2+1]-put1[k*2+1]+mod)%mod;
            p2=(put1[k*2+1]*put1[k]+put2[k*2+1]*put2[k])%mod;
            p1=(p0*put1[k]+put1[k*2+1]*put2[k])%mod;
            put1[k*2+1]=p1;
            put2[k*2+1]=p2;


            p0=(put2[k*2+2]-put1[k*2+2]+mod)%mod;
            p2=(put1[k*2+2]*put1[k]+put2[k*2+2]*put2[k])%mod;
            p1=(p0*put1[k]+put1[k*2+2]*put2[k])%mod;
            put1[k*2+2]=p1;
            put2[k*2+2]=p2;
        }
        put1[k]=0;put2[k]=1;
    }

    void add(int a,int b,int m1,int m2,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            put1[k]=m1;
            put2[k]=m2;
            push(k);
            return;
        }
        add(a,b,m1,m2,k*2+1,l,(l+r)/2);
        add(a,b,m1,m2,k*2+2,(l+r)/2,r);

        dat1[k]=(dat1[k*2+1]+dat1[k*2+2])%mod;
        dat2[k]=(dat2[k*2+1]+dat2[k*2+2])%mod;
    }
    int query(int a,int b,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return 0;
        if(a<=l&&r<=b)return dat2[k];
        return (query(a,b,k*2+1,l,(l+r)/2)+query(a,b,k*2+2,(l+r)/2,r))%mod;
    }
};

signed main(){
    A[0][0][0]=1;A[0][0][1]=1;
    A[0][1][0]=1;A[0][1][1]=0;
    for(int i=1;i<55;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    A[i][j][k]+=A[i-1][j][l]*A[i-1][l][k];
                }
                A[i][j][k]%=mod;
            }
        }
    }


    segtree seg;
    int N,Q;scanf("%lld%lld",&N,&Q);
    rep(i,N){
        int A;
        scanf("%lld",&A);
        seg.add(i,i+1,F(A),F(A+1));
    }
    while(Q--){
        int t,l,r;
        scanf("%lld%lld%lld",&t,&l,&r);
        l--;
        if(t==1){
            int v;
            scanf("%lld",&v);
            seg.add(l,r,F(v),F(v+1));
        }
        else{
            printf("%lld\n",seg.query(l,r));
        }
    }
    return 0;
}