#include <stdio.h>

#define MAXN 100005
#define TS 262144
typedef long long lld;

int N,Q,A[MAXN];
lld T[7][12][TS]; int ST=TS/2-1;

void add(lld tree[TS],int n,lld v)
{
    for (;n;n>>=1) tree[n] += v;
}

lld get_sum(lld tree[TS],int l,int r)
{
    lld ret=0;
    for (;l<=r;l>>=1,r>>=1){
        if (l&1) ret += tree[l++];
        if (!(r&1)) ret += tree[r--];
    }
    return ret;
}

inline int num(int z,int n)
{
    int k=2*(z-1);
    if (n%k == 0) return 2;
    if (n%k <= z) return n%k;
    return z+z-n%k;
}

void assign(int n,int v)
{
    int z,s;
    for (z=2;z<7;z++){
        for (s=1;s<=z+z-2;s++){
            add(T[z][s],ST+n,lld(v-A[n])*num(z,n-s+1));
        }
    }
    A[n] = v;
}

lld proc(int l,int r,int z)
{
    int s=(l-1)%(2*z-2)+1;
    return get_sum(T[z][s],ST+l,ST+r);
}

int main()
{
    int i,j,k;
    int t,a,b,c;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",&k), assign(i,k);
    for (scanf("%d",&Q);Q--;){
        scanf("%d",&t);
        if (t == 1){
            scanf("%d%d",&a,&b);
            assign(a,b);
        }else{
            scanf("%d%d%d",&a,&b,&c);
            printf("%I64d\n",proc(a,b,c));
        }
    }
}