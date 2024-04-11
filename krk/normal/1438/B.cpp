#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool sam = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            for (int j = 0; j < i; j++)
                if (a[j] == a[i]) sam = true;
        }
        printf("%s\n", sam? "YES": "NO");
    }
    return 0;
}