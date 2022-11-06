#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 150;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn][maxn];


int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i)
        gets(t[i]);
    int lx, ly, rx, ry;
    lx = ly = inf;
    rx = ry = -inf;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (t[i][j] == 'B') {
                lx = min(lx, i);
                ly = min(ly, j);
                rx = max(rx, i);
                ry = max(ry, j);
            }
    cout << 1 + (lx + rx) / 2 << ' ' << 1 + (ly + ry) / 2 << endl;
    return 0;
}