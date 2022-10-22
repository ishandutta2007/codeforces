#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int res = 0;
        int pnt = 0;
        while (pnt < n)
            if (str[pnt] == '1') res += a[pnt++];
            else {
                res += a[pnt];
                int mn = a[pnt++];
                while (pnt < n && str[pnt] == '1') {
                    res += a[pnt];
                    mn = min(mn, a[pnt++]);
                }
                res -= mn;
            }
        printf("%d\n", res);
    }
    return 0;
}