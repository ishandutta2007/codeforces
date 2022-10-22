#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int q;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]); a[i]--;
        }
        bool ok1 = true, ok2 = true;
        for (int i = 0; i < n; i++) {
            int ni = (i + 1) % n;
            if ((a[i] + 1) % n != a[ni]) ok1 = false;
            if ((a[ni] + 1) % n != a[i]) ok2 = false;
        }
        printf("%s\n", (ok1 || ok2)? "YES": "NO");
    }
    return 0;
}