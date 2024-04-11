#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n, z;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        int mx = 0;
        scanf("%d %d", &n, &z);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            mx = max(mx, (a[i] | z));
        }
        printf("%d\n", mx);
    }
    return 0;
}