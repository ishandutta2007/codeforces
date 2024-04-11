#include <stdio.h>

int N,L[5],R[5];
double f[32][10001],e[32][10001],u[32][10001];

int main()
{
    scanf ("%d",&N);
    for (int i=0;i<N;i++) scanf ("%d %d",&L[i],&R[i]);
    
    for (int j=1;j<=10000;j++) for (int k=0;k<(1<<N);k++){
        double &d = f[k][j]; d = 1;
        for (int i=0;i<N;i++) if ((1 << i) & k){
            int can;
            if (R[i] <= j) can = R[i] - L[i] + 1;
            else if (L[i] <= j) can = j - L[i] + 1;
            else can = 0;
            d *= can / (R[i] - L[i] + 1.);
        }

        double &v = u[k][j]; v = 1;
        for (int i=0;i<N;i++) if ((1 << i) & k){
            if (L[i] <= j && j <= R[i]) v *= 1. / (R[i] - L[i] + 1);
            else v = 0;
        }

        e[k][j] = e[k][j-1] + j * (f[k][j] - f[k][j-1]);
    }

    int all = (1<<N) - 1;
    double ans = e[all][1];
    for (int j=2;j<=10000;j++){
        for (int k=1;k<(1<<N);k++){
            if (k == (k & (-k))) ans += u[k][j] * e[all^k][j-1];
            else ans += j * u[k][j] * f[all^k][j-1];
        }
    }

    printf("%.12lf\n",ans);

    return 0;
}