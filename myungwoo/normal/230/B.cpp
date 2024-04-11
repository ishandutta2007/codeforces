#include <stdio.h>

typedef long long lld;

const int MAX=1000000;
int N,prime[78499],pcnt;
bool V[500001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,s,e,m;
    lld n,k;
    prime[++pcnt] = 2;
    for (i=3;i<MAX;i+=2) if (!V[i>>1]){
        prime[++pcnt] = i;
        if (i > MAX/i) continue;
        for (j=i*i;j<MAX;j+=i+i) V[j>>1] = 1;
    }
    for (scanf("%d",&N);N--;){
        scanf("%I64d",&n);
        s = 1, e = pcnt;
        while (s <= e){
            m = (s+e)>>1;
            k = lld(prime[m])*prime[m];
            if (k < n) s = m+1;
            else if (k > n) e = m-1;
            else{ puts("YES"); break; }
        }
        if (s > e) puts("NO");
    }
}