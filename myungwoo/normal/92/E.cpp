#include <stdio.h>

#define MAXN 100005
#define MOD 1000000009

int N,M,mom[MAXN],ans;

inline int par(int n){ return mom[n]==n?n:(mom[n]=par(mom[n])); }

int main()
{
    int i,a,b,p,q;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) mom[i] = i;
    while (M--){
        scanf("%d%d",&a,&b);
        p = par(a), q = par(b);
        if (p == q) ans = (ans+ans+1)%MOD;
        else mom[p] = q;
        printf("%d\n",ans);
    }
}