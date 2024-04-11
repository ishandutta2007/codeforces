#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool sam = true;
        bool zer = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i] += a[i] % 10;
            if (i && a[i] != a[i - 1]) sam = false;
            if (a[i] % 10 == 0) zer = true;
        }
        if (sam) { printf("YES\n"); continue; }
        if (zer) { printf("NO\n"); continue; }
        sam = true;
        for (int i = 0; i < n; i++) {
            while (a[i] % 10 != 2) a[i] += a[i] % 10;
            a[i] %= 20;
            if (i && a[i] != a[i - 1]) sam = false;
        }
        printf("%s\n", sam? "YES": "NO");
    }
    return 0; 
}