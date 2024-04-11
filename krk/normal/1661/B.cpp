#include <bits/stdc++.h>
using namespace std;

const int Maxb = 15;

int T;
int a;

int Need(int x)
{
    int b = 0;
    while (b < Maxb && !(x & 1 << b)) b++;
    return Maxb - b;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &a);
        int res = Need(a);
        for (int i = 1; i <= Maxb; i++) {
            int add = (1 << i) - a % (1 << i);
            res = min(res, add + Need(a + add));
        }
        printf("%d%c", res, T? ' ': '\n');
    }
    return 0;
}