#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int t;
int x, n;
int a[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &x);
        int cnt[2] = {};
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i] % 2]++;
        }
        bool ok = false;
        for (int i = 1; i <= cnt[1]; i += 2)
            if (i <= x && x - i <= cnt[0])
                ok = true;
        printf("%s\n", ok? "Yes": "No");
    }
    return 0;
}