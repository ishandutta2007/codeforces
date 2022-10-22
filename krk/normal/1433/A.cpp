#include <bits/stdc++.h>
using namespace std;

const int lim = 10000;

int T;
int x;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &x);
        int res = 0;
        bool fin = false;
        for (int d = 1; d <= 9 && !fin; d++) {
            int pr = 0;
            int cur = 0;
            while (10 * cur + d <= lim && !fin) {
                pr++;
                cur = 10 * cur + d;
                res += pr;
                fin = cur == x;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}