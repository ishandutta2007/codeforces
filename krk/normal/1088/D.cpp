#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;

int a, b;

int Get(int c, int d)
{
    printf("? %d %d\n", c, d); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Print(int a, int b)
{
    printf("! %d %d\n", a, b); fflush(stdout);
}

int main()
{
    int cur = Get(0, 0);
    int c = 0, d = 0;
    for (int i = Maxb - 1; i >= 0; i--) {
        int v1 = Get(c, d | 1 << i);
        int v2 = Get(c | 1 << i, d);
        if (v1 != 0 && v1 == -v2) {
            if (v1 == -1) ;
            else if (v1 == 1) {
                a |= 1 << i; b |= 1 << i;
                c |= 1 << i; d |= 1 << i;
            }
        } else {
            if (cur == -1) {
                b |= 1 << i;
                d |= 1 << i;
            } else {
                a |= 1 << i;
                c |= 1 << i;
            }
            cur = v1;
        }
    }
    Print(a, b);
    return 0;
}