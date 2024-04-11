#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
int a[Maxn];
ll sum;
int res[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        if (i + a[i] > n) { printf("-1\n"); return 0; }
        sum += a[i];
    }
    if (sum < n) { printf("-1\n"); return 0; }
    int lst = n + 1;
    for (int i = m - 1; i >= 0; i--) {
        int lef = max(i + 1, lst - a[i]);
        res[i] = lef; lst = lef;
    }
    for (int i = 0; i < m; i++)
        printf("%d%c", res[i], i + 1 < m? ' ': '\n');
    return 0;
}