#include <bits/stdc++.h>
using namespace std;

const int Maxb = 31;

int n, q;
int cnt[Maxb];
int mem[Maxb];

int Get(int b, int hm)
{
    if (b < 0) return -1;
    if (hm <= mem[b]) { mem[b] -= hm; return hm; }
    else {
        int res = mem[b]; hm -= mem[b]; mem[b] = 0;
        int g = Get(b - 1, hm * 2);
        if (g == -1) return -1;
        res += g;
        return res;
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        for (int j = 0; j < Maxb; j++)
            if (a & 1 << j) { cnt[j]++; break; }
    }
    while (q--) {
        for (int j = 0; j < Maxb; j++)
            mem[j] = cnt[j];
        int x; scanf("%d", &x);
        int res = 0;
        for (int i = Maxb - 1; i >= 0; i--)
            if (x & 1 << i) {
                int g = Get(i, 1);
                if (g == -1) { res = -1; break; }
                else res += g;
            }
        printf("%d\n", res);
    }
    return 0;
}