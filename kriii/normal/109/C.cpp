#include <stdio.h>

int N,P[100001]; __int64 C[100001];

bool islucky(int v)
{
    while (v){
        if (v % 10 != 4 && v % 10 != 7) return false;
        v /= 10;
    }
    return true;
}

int find(int v)
{
    if (P[v] != v) P[v] = find(P[v]);
    return P[v];
}

int main()
{
    int i,x,y,c;

    scanf ("%d",&N);
    for (i=1;i<=N;i++) P[i] = i, C[i] = 1;
    for (i=1;i<N;i++){
        scanf ("%d %d %d",&x,&y,&c);
        if (!islucky(c)){
            x = find(x); y = find(y);
            P[x] = y; C[y] += C[x];
        }
    }

    __int64 ANS = 0,V;
    for (i=1;i<=N;i++){
        V = N - C[find(i)];
        ANS += V * (V - 1);
    }
    printf ("%I64d",ANS);

    return 0;
}