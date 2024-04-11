#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2000;

int n, k;
bool was[Maxn];

bool Was(int c)
{
    printf("? %d\n", c); fflush(stdout);
    char ch; scanf(" %c", &ch);
    return ch == 'Y';
}

void Reset()
{
    printf("R\n"); fflush(stdout);
}

void Print(int x)
{
    printf("! %d\n", x); fflush(stdout);
}

void Solve(int l, int r)
{
    if (r - l + 1 <= k) {
        Reset();
        for (int i = l; i <= r; i++) if (!was[i])
            if (Was(i)) was[i] = true;
    } else {
        int m = l + r >> 1;
        Solve(l, m); Solve(m + 1, r);
        for (int i = l; i <= m; i += k) {
            int a = i, b = i + k / 2;
            Reset();
            for (int z = 0; z < k / 2; z++)
                if (!was[a + z]) Was(a + z);
                else Was(1);
            for (int j = m + 1; j <= r; j += k) {
                int c = j, d = j + k / 2;
                for (int z = 0; z < k / 2; z++)
                    if (!was[c + z]) {
                        if (Was(c + z)) was[c + z] = true;
                    } else Was(1);
                for (int z = 0; z < k / 2; z++)
                    if (!was[b + z]) {
                        if (Was(b + z)) was[b + z] = true;
                    } else Was(1);
                for (int z = 0; z < k / 2; z++)
                    if (!was[d + z]) {
                        if (Was(d + z)) was[d + z] = true;
                    } else Was(1);
                for (int z = 0; z < k / 2; z++)
                    if (!was[a + z]) {
                        if (Was(a + z)) was[a + z] = true;
                    } else Was(1);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    if (k == 1)
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                Was(i);
                if (Was(j)) was[j] = true;
            }
    else {
        Solve(1, n);
        was[1] = false;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (!was[i]) res++;
    Print(res);
    return 0;
}