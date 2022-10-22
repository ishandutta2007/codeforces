#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
int X[Maxn], Y[Maxn];

bool inLine(int a, int b, int c)
{
    int ax = X[b] - X[a], ay = Y[b] - Y[a];
    int bx = X[c] - X[a], by = Y[c] - Y[a];
    return ll(ax) * by - ll(ay) * bx == 0;
}

bool Solve()
{
    if (n == 1) return true;
    int a, b;
    do {
        a = uniform_int_distribution<int>(0, n - 1)(rng);
        b = uniform_int_distribution<int>(0, n - 1)(rng);
    } while (a == b);
    int seq[2], slen = 0;
    for (int i = 0; i < n; i++) if (i != a && i != b)
        if (!inLine(i, a, b))
            if (slen < 2) seq[slen++] = i;
            else if (!inLine(i, seq[0], seq[1]))
                    return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 0; i < 100; i++)
        if (Solve()) { printf("YES\n"); return 0; }
    printf("NO\n");
    return 0;
}