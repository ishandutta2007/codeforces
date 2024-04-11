#include <stdio.h>

int max(int a, int b){return a<b?b:a;}

int main()
{
    int tux;
    scanf ("%d",&tux);

    int foo = 0, bar = 0, baz = 0, quz = 0;
    for (;tux>0;tux--){
        int pur;
        scanf ("%d",&pur);
        foo = foo + pur;
        bar = bar + 1;
        if (max(foo*quz,bar*baz) == foo*quz){
            baz = foo;
            quz = bar;
        }
    }

    printf ("%.6lf",baz*1./quz);

    return 0;
}