#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 300005
#define TS 1048576

int N,M,X[MAXN],tree[TS],ST=TS/2-1;

void update(int l,int r,int v)
{
    for (l+=ST,r+=ST;l<=r;l>>=1,r>>=1){
        if (l&1){
            tree[l] = min(tree[l],v);
            l++;
        }
        if (!(r&1)){
            tree[r] = min(tree[r],v);
            r--;
        }
    }
}

int main()
{
    int i,l,r,n,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<TS;i++) tree[i] = M+1;
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&l,&r,X+i);
        update(l,X[i]-1,i);
        update(X[i]+1,r,i);
    }
    for (i=1;i<=N;i++){
        k = M+1;
        for (n=ST+i;n;n>>=1) k = min(k,tree[n]);
        printf("%d ",X[k]);
    } puts("");
}