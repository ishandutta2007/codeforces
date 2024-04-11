#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, m, c;
int a[Maxn], b[Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        b[i] = (b[i - 1] + b[i]) % c;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = (a[i] + b[min(m, i)] - b[max(1, m - (n - i)) - 1] + c) % c;
        printf("%d%c", a[i], i < n? ' ': '\n');
    }
    return 0;
}