#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int has[4];
int seq[Maxn], slen;

bool Solve(int a, int ca, int b, int cb, int c, int cc, int d, int cd)
{
    if (abs(ca + cc - (cb + cd)) > 1 || ca + cc < cb + cd ||
        (ca > cb && (cc > 0 || cd > 0))) return false;
    slen = 0;
    while (ca > 0) {
        seq[slen++] = a; ca--;
        if (cb > 0) { seq[slen++] = b; cb--; }
    }
    while (cc > 0) {
        seq[slen++] = c; cc--;
        if (cb > 0) { seq[slen++] = b; cb--; }
        else if (cd > 0) { seq[slen++] = d; cd--; }
        else break;
    }
    if (slen >= n) {
        printf("YES\n");
        for (int i = 0; i < slen; i++)
            printf("%d%c", seq[i], i + 1 < slen? ' ': '\n');
        return true;
    }
    return false;
}

int main()
{
    for (int i = 0; i < 4; i++) {
        scanf("%d", &has[i]);
        n += has[i];
    }
    if (Solve(0, has[0], 1, has[1], 2, has[2], 3, has[3])) return 0;
    if (Solve(3, has[3], 2, has[2], 1, has[1], 0, has[0])) return 0;
    printf("NO\n");
    return 0;
}