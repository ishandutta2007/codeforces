#include <stdio.h>
#include <algorithm>
using namespace std;

int N; double S[111];

int main()
{
    int i;

    scanf ("%d",&N);
    for (int i=0;i<N;i++) scanf ("%lf",&S[i]);
    sort(S,S+N);

    double a = 0;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++){
        double v = 0;
        for (int k=i;k<=j;k++){
            double u = 1;
            for (int l=i;l<=j;l++) u *= (l == k) ? S[l] : 1 - S[l];
            v += u;
        }
        if (a < v)
            a = v;
    }

    printf ("%.10lf\n",a);

    return 0;
}