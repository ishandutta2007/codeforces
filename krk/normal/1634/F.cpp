#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, q, mod;
int C[Maxn];
int zers;
int F[Maxn];

void Add(int x, bool neg, int ind)
{
    if (x < 1 || x > n) return;
    int val = F[ind];
    if (neg) val = (mod - val) % mod;
    zers -= C[x] == 0;
    C[x] = (C[x] + val) % mod;
    zers += C[x] == 0;
}

int main()
{
    scanf("%d %d %d", &n, &q, &mod);
    F[1] = 1 % mod;
    for (int i = 2; i <= n; i++)
        F[i] = (F[i - 1] + F[i - 2]) % mod;
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        C[i] = a;
    }
    for (int i = 1; i <= n; i++) {
        int b; scanf("%d", &b);
        C[i] = (C[i] - b + mod) % mod;
    }
    for (int i = n; i >= 1; i--) {
        C[i] = (C[i] - C[i - 1] + mod) % mod;
        if (i >= 2) C[i] = (C[i] - C[i - 2] + mod) % mod;
        zers += C[i] == 0;
    }
    while (q--) {
        char ch;
        int l, r;
        scanf(" %c %d %d", &ch, &l, &r);
        Add(l, ch == 'B', 1);
        Add(r + 1, ch == 'A', r + 2 - l);
        Add(r + 2, ch == 'A', r + 1 - l);
        printf("%s\n", zers == n? "YES": "NO");
    }
    return 0;
}