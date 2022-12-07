#include<cmath>
#include<cstdio>

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    b/=a;
    c/=a;
    double r=sqrt(b*b-4*c);
    printf("%.8f\n%.8f\n", (-b+r)/2, (-b-r)/2);
}