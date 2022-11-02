#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c;

int main() {
    cin >> a >> b >> c;
    printf("First\n");
    int p = 0;
    long long Max = a, px = 1, Min = a, pm = 1;
       if (b > Max)
           Max = b, px = 2;
       if (c > Max)
           Max = c, px = 3;
       if (b < Min)
           Min = b, pm = 2;
       if (c < Min)
           Min = c, pm = 3;
       if (p != px) {
           printf("%d\n", Max - Min);
       }
    long long tmp = Max - Min;
    for (; ;) {
       fflush(stdout);
       int x;       
       scanf("%d", &x);
       if (!x)
           return 0;
       p = x;
       if (x == 1)
           a += tmp;
       if (x == 2)
           b += tmp;
       if (x == 3)
           c += tmp;
       long long Max = a, px = 1, Min = a, pm = 1;
       if (b > Max)
           Max = b, px = 2;
       if (c > Max)
           Max = c, px = 3;
       if (b < Min)
           Min = b, pm = 2;
       if (c < Min)
           Min = c, pm = 3;
       long long M = 0;
       if (px != 1 && pm != 1)
           M = a;
       else
           if (px != 2 && pm != 2)
               M = b;
           else
               M = c;
       if (p != px) {
           printf("%lld\n", Max - Min);
           tmp = Max - Min;
       } else 
           if (Max + Min == 2 * M) {
               printf("%lld\n", Max - M);
               tmp = Max - M;
           } else {
                printf("%lld\n", 3 * Max - a - b - c);
                tmp  = 3 * Max - a - b - c;
            }
    }       
}