#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
bool was[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(was, was + n, false);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            int md = (i + a[i]) % n;
            if (md < 0) md += n;
            was[md] = true;
        }
        bool ok = true;
        for (int i = 0; i < n && ok; i++)
            ok = was[i];
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}