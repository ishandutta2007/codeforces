#include <stdio.h>
#include <iostream>
using namespace std;
main()
{
    int n, h, m;
    scanf("%d\n%d:%d",&n,&h,&m);
    if (n == 12)
    {
        if (h > 12) h = h % 10;
        if (h == 0) h = 10;
    }
    else if (h > 23) h = h % 10;
    if (m > 59) m = m % 10;
    cout<<h/10<<h%10<<':'<<m/10<<m%10;
}