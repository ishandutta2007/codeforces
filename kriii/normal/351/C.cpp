#include <stdio.h>
#include <functional>
#include <map>
using namespace std;

map<int, int> U;
int A[22],B[22],S;
long long N,M,V,W,ans;

int main()
{
    int i,j,x;

    scanf ("%lld %lld",&N,&M); V = 2 * N * N;
    for (i=0;i<N;i++) scanf ("%d",&A[i]);
    for (i=0;i<N;i++) scanf ("%d",&B[i]);

    W = N * M;
    for (x=i=0;i<V+W%V;i++){
        U[A[x]-B[x]]++;
        S += B[x];
        if (i % 2 == 0){
            S += U.begin()->first;
            if (--U.begin()->second == 0) U.erase(U.begin());
        }
        if (++x >= N) x = 0;
        if (i+1 == W){
            printf ("%lld",S); return 0;
        }
    }

    ans = S;
    W -= V;

    W /= V;
    S = 0;
    for (j=0;j<V;i++,j++){
        U[A[x]-B[x]]++;
        S += B[x];
        if (i % 2 == 0){
            S += U.begin()->first;
            if (--U.begin()->second == 0) U.erase(U.begin());
        }
        if (++x >= N) x = 0;
    }
    ans += S * W;

    printf ("%lld",ans);

    return 0;
}