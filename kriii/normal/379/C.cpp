#include <stdio.h>
#include <algorithm>

struct v{
    int a,i;
}V[300010];
bool cmp(const v& a, const v& b){return a.a < b.a;}

int N,A[300010],X;

int main()
{
    int i;

    scanf ("%d",&N);
    for (i=0;i<N;i++){
        scanf ("%d",&V[i].a);
        V[i].i = i;
    }
    std::sort(V,V+N,cmp);

    for (i=0;i<N;i++){
        if (X < V[i].a)
            X = V[i].a;
        else
            X++;

        A[V[i].i] = X;
    }

    for (i=0;i<N;i++) printf ("%d ",A[i]);

    return 0;
}