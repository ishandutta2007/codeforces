#include <bits/stdc++.h>
using namespace std;

int q;
int a;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &a);
        bool was = false;
        int full = 0;
        for (int i = 0; (1 << i) <= a; i++) {
            full |= 1 << i;
            if (!(a & 1 << i)) was = true;
        }
        if (was) printf("%d\n", full);
        else {
            int val = 1;
            for (int i = 2; i * i <= a; i++) if (a % i == 0) {
                val = a / i; break;
            }
            printf("%d\n", val);
        }
    }
    return 0;
}