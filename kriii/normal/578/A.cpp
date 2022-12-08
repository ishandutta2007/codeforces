#include <stdio.h>

int main()
{
    int a,b;
    scanf ("%d %d",&a,&b);

    if (a < b) puts("-1");
    else if (a == b) printf ("%.12lf\n",(double)a);
    else{
        double ans1 = (a - b) / (2. * ((a - b) / (2 * b)));
        double ans2 = (a + b) / (2. * ((a + b) / (2 * b)));
        double ans = ans1 < ans2 ? ans1 : ans2;
        printf ("%.12lf\n",ans);
    }
    return 0;
}