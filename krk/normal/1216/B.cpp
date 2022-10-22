#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
ii a[Maxn];
int res = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    int x = 0;
    for (int i = n - 1; i >= 0; i--) {
        res += x * a[i].first + 1;
        x++;
    }
    printf("%d\n", res);
    for (int i = n - 1; i >= 0; i--)
        printf("%d%c", a[i].second + 1, i - 1 >= 0? ' ': '\n');
    return 0;
}