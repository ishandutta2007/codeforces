#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a,b,c,d;

    scanf ("%d %d %d %d",&a,&b,&c,&d);

    bool good = 0;
    if (a+b<=max(c,d)) good = 1;
    if (a <= c && b <= d) good = 1;
    puts(good?"Polycarp":"Vasiliy");

    return 0;
}