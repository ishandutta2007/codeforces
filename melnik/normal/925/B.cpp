#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 300500;
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;

pair <int, int> a[maxn];

void Solve(int idx, int n, int x1, int x2, bool was_rev) {
    int c = a[idx].f;
    int k = (x1 + c - 1) / c;
    int new_idx = idx + k;
    if (new_idx > n)
        return;
    if (1LL * a[new_idx].f * (n - new_idx + 1) < x2)
        return;
    if (!was_rev) {
        printf ("Yes\n");
        printf ("%d %d\n", k, n - new_idx + 1);
        for (int i = idx; i < idx + k; ++i)
            printf ("%d ", a[i].s);
        printf ("\n");
        for (int i = idx + k; i <= n; ++i)
            printf ("%d ", a[i].s);
        exit(0);
    }
    printf ("Yes\n");
    printf ("%d %d\n", n - new_idx + 1, k);
    for (int i = idx + k; i <= n; ++i)
        printf ("%d ", a[i].s);
    printf ("\n");
    for (int i = idx; i < idx + k; ++i)
        printf ("%d ", a[i].s);
    exit(0);
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // ios_base::sync_with_stdio(false);
    int n, x1, x2;
    scanf ("%d%d%d", &n, &x1, &x2);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf ("%d", &x);
        a[i] = mp(x, i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        Solve(i, n, x1, x2, false);
        Solve(i, n, x2, x1, true);
    }
    printf ("No\n");
    
}