#include <stdio.h>
#include <algorithm>
using namespace std;

int N, A[200200];

double f(double x)
{
    double mx = A[0] - x, mn = A[0] - x;
    double smx = 0, smn = 0;
    for (int i=0;i<N;i++){
        double v = A[i] - x;
        smx += v;
        smn += v;
        mx = max(mx,smx);
        mn = min(mn,smn);
        if (smx < 0) smx = 0;
        if (smn > 0) smn = 0;
    }
    return max(abs(mx),abs(mn));
}

int main()
{
    scanf ("%d",&N);
    for (int i=0;i<N;i++) scanf ("%d",&A[i]);

    double l = -1e12, r = 1e12;
    for (int i=0;i<=200;i++){
        double ll = (l * 2 + r) / 3;
        double rr = (l + 2 * r) / 3;
        double u = f(ll), v = f(rr);
        if (u <= v) r = rr;
        else l = ll;
    }
    printf ("%.12lf\n",f(l));

    return 0;
}