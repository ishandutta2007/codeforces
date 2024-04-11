#include <stdio.h>

#define MAXN 100005
#define MOD 1000000009

int N,M,mom[MAXN],rnk[MAXN],ans;

int find(int n)
{
    if (mom[n] != n) mom[n] = find(mom[n]);
    return mom[n];
}

bool un(int a,int b)
{
    a = find(a), b = find(b);
    if (a != b){
        if (rnk[a] < rnk[b]) mom[a] = b;
        else{
            mom[b] = a;
            if (rnk[a] == rnk[b]) rnk[a]++;
        }
        return 1;
    }
    return 0;
}

int main()
{
    int i,j;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) mom[i] = i;
    while (M--){
        scanf("%d%d",&i,&j);
        if (!un(i,j)) ans = (ans+ans+1)%MOD;
        printf("%d\n",ans);
    }
}