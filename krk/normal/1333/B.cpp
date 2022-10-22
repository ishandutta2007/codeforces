#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        bool neg = false, pos = false;
        bool ok = true;
        for (int i = 0; i < n && ok; i++) {
            if (b[i] < a[i]) ok = neg;
            else if (b[i] > a[i]) ok = pos;
            if (a[i] == -1) neg = true;
            if (a[i] == 1) pos = true;
        }
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}