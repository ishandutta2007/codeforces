#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxd = 4;
const ll mod = 1000000007;

int n;
int A[Maxd][Maxd], B[Maxd][Maxd];

void Mult(int A[][Maxd], int B[][Maxd])
{
    int C[Maxd][Maxd];
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxd; j++) {
            C[i][j] = 0;
            for (int k = 0; k < Maxd; k++)
                C[i][j] = (C[i][j] + ll(A[i][k]) * ll(B[k][j]) % mod) % mod;
        }
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxd; j++) A[i][j] = C[i][j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxd; j++)
            if (i == j) { A[i][j] = 1; B[i][j] = 0; }
            else { A[i][j] = 0; B[i][j] = 1; }
    while (n) {
        if (n & 1) Mult(A, B);
        Mult(B, B);
        n >>= 1;
    }
    printf("%d\n", A[Maxd - 1][Maxd - 1]);
    return 0;
}