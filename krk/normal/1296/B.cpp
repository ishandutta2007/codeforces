#include <bits/stdc++.h>
using namespace std;

int T;
int x;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &x);
        int res = 0;
        while (x >= 10) {
            int tk = x / 10;
            res += tk * 10;
            x = x % 10 + tk;
        }
        res += x;
        printf("%d\n", res);
    }
    return 0;
}