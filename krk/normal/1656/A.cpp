#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n;
ii a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a, a + n);
        printf("%d %d\n", a[0].second + 1, a[n - 1].second + 1);
    }
    return 0;
}