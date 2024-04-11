#include <bits/stdc++.h>
using namespace std;

#define bit(n) (1<<(n))

int N, M;
int w[20][20];
int D[1<<20], V[20], C[20][20], CM[20][20];
char A[20][21];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;i++) scanf("%s", A[i]);
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) scanf("%d", w[i]+j);
    for (int i=0;i<bit(N);i++) D[i] = 2e9;
    D[0] = 0;
    for (int i=0;i<N;i++){
        V[i] = 2e9;
        for (int j=0;j<M;j++){
            V[i] = min(V[i], w[i][j]);
            for (int k=0;k<N;k++) if (A[i][j] == A[k][j] && i != k){
                C[i][j] += w[k][j];
                CM[i][j] |= bit(k);
            }
        }
    }
    for (int msk=0;msk<bit(N);msk++) if (D[msk] < 2e9){
        for (int i=0;i<N;i++) if (!(msk&bit(i))){
            int t = msk | bit(i);
            D[t] = min(D[t], D[msk] + V[i]);
            for (int j=0;j<M;j++){
                t = msk | bit(i) | CM[i][j];
                D[t] = min(D[t], D[msk] + C[i][j]);
            }
        }
    }
    printf("%d\n", D[bit(N)-1]);
}