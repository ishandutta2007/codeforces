#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            cnt += a[i] < 0;
            a[i] = abs(a[i]);
        }
        for (int i = 0; i < cnt; i++)
            a[i] = -a[i];
        bool ok = true;
        for (int i = 0; i + 1 < n && ok; i++)
            ok = a[i] <= a[i + 1];
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}