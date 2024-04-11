#include <stdio.h>

const long long mod = 1000000007;

struct matrix{
    int N; long long A[82][82];
    matrix(int n){
        N = n;
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j] = 0;
    }
    
    matrix operator +(matrix t){
        matrix res(N);
        for (int i=0;i<N;i++) for (int j=0;j<N;j++) res.A[i][j] = (A[i][j] + t.A[i][j]) % mod;
        return res;
    }

    matrix operator *(matrix t){
        matrix res(N);
        for (int i=0;i<N;i++) for (int j=0;j<N;j++) for (int k=0;k<N;k++) res.A[i][j] = (res.A[i][j] + A[i][k] * t.A[k][j]) % mod;
        return res;
    }
};

long long bi[44][44],pw[44];

int main()
{
    long long N; int K;
    scanf ("%lld %d",&N,&K);
    for (int i=0;i<=K;i++){
        bi[i][0] = bi[i][i] = 1;
        for (int j=1;j<i;j++) bi[i][j] = (bi[i-1][j-1] + bi[i-1][j]) % mod;
        pw[i] = (1ll << i) % mod;
    }

    matrix A(2*(K+1));
    for (int i=0;i<=K;i++){
        A.A[i+K+1][i] = 1;
        for (int j=0;j<=i;j++){
            A.A[i][j] = bi[i][j];
            A.A[i][j+K+1] = bi[i][j] * pw[i-j] % mod;
        }
    }

    matrix R(2*(K+1)),P(2*(K+1));
    for (int i=0;i<P.N;i++) P.A[i][i] = 1;
    while (N){
        if (N & 1){
            R = R * A + P;
        }
        P = P * A + P;
        A = A * A;
        N >>= 1;
    }

    long long ans = 0;
    for (int i=0;i<=K+1;i++){
        ans += R.A[K][i];
    }
    printf ("%lld\n",ans%mod);

    return 0;
}