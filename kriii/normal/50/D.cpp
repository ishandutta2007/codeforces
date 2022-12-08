#include <stdio.h>
#include <algorithm>
#include <math.h>

int N,K; double E,D2[111];

bool CHK(double R)
{
    int i,j,c=K,p;
    
    for (i=0;i<N;i++){if (R * R <= D2[i]) break;} p = i; c -= p;

    if (c <= 0) return true;
    if (N - p < c) return false;
    
    double PR[111][111],P[111];

    for (i=p;i<N;i++) P[i] = exp(1-D2[i]/(R * R));
    PR[p][0] = 1 - P[p]; PR[p][1] = P[p]; for (i=2;i<=c;i++) PR[p][i] = 0;
    for (i=p+1;i<N;i++){
        PR[i][0] = PR[i-1][0] * (1 - P[i]);
        for (j=1;j<c;j++) PR[i][j] = PR[i-1][j-1] * P[i] + PR[i-1][j] * (1 - P[i]);
        PR[i][c] = PR[i-1][c-1] * P[i] + PR[i-1][c];
    }

    if (PR[N-1][c] >= E) return true;
    return false;
}

int main()
{
    int i; double x,y,p,q;

    scanf ("%d %d %lf",&N,&K,&E); E /= 1000; E = 1 - E;
    scanf ("%lf %lf",&x,&y);
    for (i=0;i<N;i++){scanf ("%lf %lf",&p,&q); D2[i] = (x-p)*(x-p)+(y-q)*(y-q);}
    std::sort(D2,D2+N);

    double L=0, R=10000, M;
    for (i=0;i<100;i++){
        M = (L + R) / 2;
        if (CHK(M)) R = M;
        else L = M;
    }

    printf ("%.12lf",M);

    return 0;
}