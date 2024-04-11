#include <stdio.h>

#define MAXN 100005
#define MOD 1000000007

int N,mom[MAXN],V[MAXN],ans;

int find(int n)
{
    if (mom[n] == n) return n;
    int k=mom[n];
    mom[n] = find(mom[n]);
    V[n] = (V[n]+V[k])%MOD;
    return mom[n];
}

int main()
{
    int i,j,k,x,n;
    scanf("%d",&N);
    for (i=1;i<=N;i++) mom[i] = i;
    for (i=1;i<=N;i++){
        for (scanf("%d",&k);k--;){
            scanf("%d%d",&j,&x);
            n = find(j);
            mom[n] = i; V[n] = (V[j]+x)%MOD;
            ans = (ans+V[n])%MOD;
        }
    }
    printf("%d",ans<0?ans+MOD:ans);
}