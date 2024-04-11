#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test;
long long n, k, d1, d2;

int main(){
    scanf("%d", &test);
    for (;test--;)
    {
        scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
        if (n % 3)
        {
            printf("no\n");
            continue;
        }
        if (d1 + d2 + d2 <= n - k && d1 + d1 + d2 <= k && !((n - (d1 + d2 + d2) - k) % 3)) 
        {
            printf("yes\n");
            continue;
        }
        if (d1 + d1 + d2 <= n - k && d1 + d2 + d2 <= k && !((n - (d1 + d1 + d2) - k) % 3))
        {
            printf("yes\n");
            continue;
        }
        if  (d1 + d2 <= n - k && max(d1, d2) + max(d1, d2) - min(d1, d2) <= k && !((n - d1 - d2 - k) % 3))
        {
            printf("yes\n");
            continue;
        }
        if  (max(d1, d2) + max(d1, d2) - min(d1, d2) <= n - k && d1 + d2 <= k && !((n - max(d1, d2) - max(d1, d2) + min(d1, d2) - k) % 3))
        {
            printf("yes\n");
            continue;
        }
        else printf("no\n");
    }
}