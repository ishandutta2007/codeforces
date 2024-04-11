#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int Ask(int a, int b, int c)
{
    printf("? %d %d %d\n", a, b, c); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Print(int a, int b)
{
    printf("! %d %d\n", a, b); fflush(stdout);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int best = -1, ind;
        for (int i = 3; i <= n; i++) {
            int got = Ask(1, 2, i);
            if (got > best) { best = got; ind = i; }
        }
        int a = 1, b = ind;
        best = -1;
        for (int i = 1; i <= n; i++) if (i != a && i != b) {
            int got = Ask(a, b, i);
            if (got > best) { best = got; ind = i; }
        }
        int d = 1;
        while (d == a || d == b || d == ind) d++;
        if (Ask(a, b, d) == best) Print(a, b);
        else if (Ask(b, ind, d) == best) Print(b, ind);
        else Print(a, ind);
    }
    return 0;
}