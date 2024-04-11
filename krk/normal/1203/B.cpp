#include <bits/stdc++.h>
using namespace std;

const int Maxn = 405;

int q;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < 4 * n; i++)
            scanf("%d", &a[i]);
        sort(a, a + 4 * n);
        bool ok = true;
        int l = 0, r = 4 * n - 1;
        int area = -1;
        while (l <= r && ok) {
            int a1 = a[l++];
            int a2 = a[l++];
            int b1 = a[r--];
            int b2 = a[r--];
            if (a1 == a2 && b1 == b2 && (area == -1 || area == a1 * b1))
                area = a1 * b1;
            else ok = false;
        }
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}