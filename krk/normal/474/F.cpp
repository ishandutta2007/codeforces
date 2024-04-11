#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;

int n;
int a[Maxn];
int g[Maxm];
vector <int> un;
vector <int> V[Maxn];
int t;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void Create(int v, int l, int r)
{
    if (l == r) g[v] = a[l];
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
        g[v] = gcd(g[2 * v], g[2 * v + 1]);
    }
}

int Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return g[v];
    else {
        int res = 0;
        int m = l + r >> 1;
        if (a <= m) res = gcd(res, Get(2 * v, l, m, a, min(m, b)));
        if (m + 1 <= b) res = gcd(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
        return res;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 1; i <= n; i++)
        V[lower_bound(un.begin(), un.end(), a[i]) - un.begin()].push_back(i);
    Create(1, 1, n);
    scanf("%d", &t);
    while (t--) {
        int l, r; scanf("%d %d", &l, &r);
        int g = Get(1, 1, n, l, r);
        int sub = 0;
        int ind = lower_bound(un.begin(), un.end(), g) - un.begin();
        if (0 <= ind && ind < un.size() && un[ind] == g)
            sub = upper_bound(V[ind].begin(), V[ind].end(), r) - lower_bound(V[ind].begin(), V[ind].end(), l);
        printf("%d\n", r - l + 1 - sub);
    }
    return 0;
}