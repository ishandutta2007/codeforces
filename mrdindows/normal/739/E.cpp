#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)

using namespace std;

const int N = 2048;

float d[N][N];

double A[N];
double B[N];


int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    forn(i, n) scanf("%lf", &A[i]);
    forn(i, n) scanf("%lf", &B[i]);

    forn(i, n)
    {
        float aa = A[i];
        float bb = B[i];
        float cc = A[i] + B[i] - A[i] * B[i];

        int mxa = min(a, i);
        int mxb = min(b, i);
        int mna = max(0, a - n + i);
        int mnb = max(0, b - n + i);

        for (int j = mxa; j >= mna; --j) for (int k = mxb; k >= mnb; --k)
        {
            d[j + 1][k] = max(d[j + 1][k], d[j][k] + aa);
            d[j][k + 1] = max(d[j][k + 1], d[j][k] + bb);
            d[j + 1][k + 1] = max(d[j + 1][k + 1], d[j][k] + cc);
        }
    }
    printf("%.10f\n", (double)d[a][b]);
    return 0;
}