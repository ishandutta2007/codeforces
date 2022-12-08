#include <stdio.h>
#include <algorithm>

int main()
{
    int a,b; scanf ("%d %d",&a,&b);
    int m = std::min(a,b);
    puts(m%2?"Akshat":"Malvika");

    return 0;
}