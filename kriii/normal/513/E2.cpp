#include <stdio.h>

int N,K,S[30003],P[201][30003],Q[201][30003];

int main()
{
    scanf ("%d %d",&N,&K);
    for (int i=1;i<=N;i++){
        scanf ("%d",&S[i]);
        S[i] += S[i-1];
    }

    for (int k=1;k<K;k++){
        if (k == 1){
            int p = 0, q = 0;
            for (int j=1;j<=N;j++){
                P[k][j] = S[j] - p;
                Q[k][j] = q - S[j];
                if (p > S[j]) p = S[j];
                if (q < S[j]) q = S[j];
            }
        }
        else{
            int p = P[k-1][k-1] + S[k-1] * 2, q = Q[k-1][k-1] - S[k-1] * 2;
            int r = P[k-1][k-1], s = Q[k-1][k-1];
            for (int j=k;j<=N;j++){
                P[k][j] = q + S[j] * 2;
                if (P[k][j] < r)
                    P[k][j] = r;
                Q[k][j] = p - S[j] * 2;
                if (Q[k][j] < s)
                    Q[k][j] = s;
                if (p < P[k-1][j] + S[j] * 2)
                    p = P[k-1][j] + S[j] * 2;
                if (q < Q[k-1][j] - S[j] * 2)
                    q = Q[k-1][j] - S[j] * 2;
                if (r < P[k-1][j])
                    r = P[k-1][j];
                if (s < Q[k-1][j])
                    s = Q[k-1][j];
            }
        }
    }

    int ans = 0x80000000;
    int p = P[K-1][K-1] + S[K-1], q = Q[K-1][K-1] - S[K-1];
    for (int j=K;j<=N;j++){
        if (ans < p - S[j])
            ans = p - S[j];
        if (ans < q + S[j])
            ans = q + S[j];
        if (p < P[K-1][j] + S[j])
            p = P[K-1][j] + S[j];
        if (q < Q[K-1][j] - S[j])
            q = Q[K-1][j] - S[j];
    }

    printf ("%d\n",ans);

    return 0;
}