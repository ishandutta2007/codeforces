#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 1000000000;
const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int m;
int b[Maxn];

bool Exists(ll x)
{
    if (x < -Inf || x > Inf) return false;
    int ind = lower_bound(a, a + n, x) - a;
    return ind < n && a[ind] == x;
}

bool Solve()
{
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            for (int k = j + 1; k < m; k++)
                if (!Exists(ll(b[i]) + b[j] + b[k])) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        m = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[j] == a[i]) j++;
            int tk = min(j - i, 3);
            while (tk--) b[m++] = a[i];
        }
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}