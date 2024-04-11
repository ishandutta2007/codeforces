#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        bool ok = false;
        for (int i = 0; i < n; i++) {
            int ind = lower_bound(a + i + 1, a + n, a[i] + k) - a;
            if (ind < n && a[ind] == a[i] + k) ok = true;
        }
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}