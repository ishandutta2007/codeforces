#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define MOD 1000000007
#define TS 524288

int N,M,D[MAXN*2],X[MAXN*2],XC;
int tree[TS],ST=TS/2-1;

struct Z{
    int s,e;
    bool operator < (const Z &b)const{
        return e<b.e;
    }
} A[MAXN];

int find(int t)
{
    int s=1,e=XC,m;
    while (s <= e){
        m = (s+e)>>1;
        if (X[m] == t) return m;
        if (X[m] < t) s = m+1;
        else e = m-1;
    }
    return 0;
}

int search(int l,int r)
{
    int ret=0;
    while (l < r){
        if (l&1){
            ret = (ret+tree[l])%MOD;
            l++;
        }
        if (!(r&1)){
            ret = (ret+tree[r])%MOD;
            r--;
        }
        l >>= 1, r >>= 1;
    }
    if (l == r) ret = (ret+tree[l])%MOD;
    return ret;
}

void update(int n,int v)
{
    tree[n] = v;
    for (n>>=1;n;n>>=1) tree[n] = (tree[n+n]+tree[n+n+1])%MOD;
}

int main()
{
    int i;
    scanf("%d%d",&M,&N); X[++XC] = 0, X[++XC] = M;
    for (i=1;i<=N;i++) scanf("%d%d",&A[i].s,&A[i].e), X[++XC] = A[i].s, X[++XC] = A[i].e;
    sort(A+1,A+N+1); sort(X+1,X+XC+1); XC = unique(X+1,X+XC+1)-X-1;
    for (i=1;i<=N;i++) A[i].s = find(A[i].s), A[i].e = find(A[i].e);
    D[1] = 1; update(ST+1,D[1]);
    for (i=1;i<=N;i++){
        D[A[i].e] = (D[A[i].e]+search(ST+A[i].s,ST+A[i].e-1))%MOD;
        update(ST+A[i].e,D[A[i].e]);
    }
    printf("%d",D[XC]);
}