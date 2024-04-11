#include <stdio.h>
#include <math.h>

double r;
int a,h;

int main()
{
    scanf ("%lf",&r);
    for (int a=1;a<=10;a++) for (int h=1;h<=10;h++){
        double pr = a * h / hypot(a,2*h);
        if (fabs(r-pr) < 1e-5){
            printf ("%d %d\n",a,h);
            return 0 ;
        }
    }

    return 0;
}