#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n % 7)
            if (n % 10 > n % 7) n -= n % 7;
            else n += (7 - n % 7) % 7;
        printf("%d\n", n);
    }
    return 0;
}