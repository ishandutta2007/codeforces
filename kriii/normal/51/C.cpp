#include <stdio.h>
#include <algorithm>

int N; double X[202020],a,b,c,p,A,B,C;

bool CHK(double d)
{
    int i,x = 0;

    a = X[x] + d;
    for (i=x+1;i<N;i++){if (X[i] > a + d) break;} x = i;
    if (x == N){b = a + d*2+1; c = b + d*2+1; return true;}

    b = X[x] + d;
    for (i=x+1;i<N;i++){if (X[i] > b + d) break;} x = i;
    if (x == N){c = b + d*2+1; return true;}

    c = X[x] + d;
    if (X[N-1] > c + d) return false;
    return true;
}

int main()
{
    int i;

    scanf ("%d",&N);
    for (i=0;i<N;i++) scanf ("%lf",&X[i]);
    std::sort(X,X+N);

    double l = 0, r = 3e9; double m; p = 3e9;
    for (i=0;i<150;i++){
        m = double(l + r) / 2;
        if (CHK(m)){
            r = m;
            if (p > m) p = m, A = a, B = b, C = c;
        }
        else l = m;
    }

    printf ("%.6lf\n%.6lf %.6lf %.6lf",p,A,B,C);

    return 0;
}