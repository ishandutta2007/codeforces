#include <bits/stdc++.h>
using namespace std;

int T;
int k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &k);
        int r = 1, c = 1;
        while (r + c - 1 < k) { k -= (r + c - 1); r++; c++; }
        if (k <= r) printf("%d %d\n", k, c);
        else {
            k -= r;
            printf("%d %d\n", r, c - k);
        }
    }
    return 0;
}