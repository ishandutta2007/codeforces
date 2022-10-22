#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int m;
ii b[Maxn];

int Get(int x)
{
    int ind = lower_bound(b, b + m, ii(x, 0)) - b;
    if (ind < m) return b[ind].second;
    return 0;
}

int Solve()
{
    sort(b, b + m);
    for (int i = m - 2; i >= 0; i--)
        b[i].second = max(b[i].second, b[i + 1].second);
    int res = 0;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        int mx = a[i];
        while (j < n) {
            mx = max(mx, a[j]);
            if (Get(mx) >= j - i + 1) j++;
            else break;
        }
        res++;
        if (j == i) return -1;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%d %d", &b[i].first, &b[i].second);
        printf("%d\n", Solve());
    }
    return 0;
}