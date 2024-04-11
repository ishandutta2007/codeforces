#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

vector <int> my[Maxn];
int n, m;
int best[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int Ask(int h, int w, int r1, int c1, int r2, int c2)
{
    printf("? %d %d %d %d %d %d\n", h, w, r1, c1, r2, c2); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

bool Check(int w, int n, int m, bool byrow)
{
    int sz = n / w;
    int row = 1;
    while (sz > 1) {
        int hf = sz / 2;
        int g = byrow? Ask(w * hf, m, row, 1, row + w * hf, 1):
                       Ask(m, w * hf, 1, row, 1, row + w * hf);
        if (!g) return false;
        sz -= hf;
        row += w * hf;
    }
    return true;
}

int Solve(bool byrow)
{
    int th = byrow? n: m;
    int oth = byrow? m: n;
    for (int i = 1; i <= th; i++)
        best[i] = th;
    for (int i = th - 1; i > 0; i--) if (th % i == 0) {
        int good = best[i] != -1 && best[i] % i == 0 && Check(i, best[i], oth, byrow);
        for (int j = 0; j < my[i].size(); j++) {
            int v = my[i][j];
            if (good) best[v] = gcd(best[v], i);
            else best[v] = -1;
        }
    }
    int res = 0;
    for (int i = 1; i <= th; i++) if (th % i == 0)
        res += best[i] != -1;
    return res;
}

int main()
{
    for (int i = 1; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i)
            my[j].push_back(i);
    scanf("%d %d", &n, &m);
    int a = Solve(true);
    int b = Solve(false);
    printf("! %d\n", a * b); fflush(stdout);
    return 0;
}