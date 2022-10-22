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
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int pnt = 1;
        while (pnt < n && a[pnt - 1] > a[pnt]) pnt++;
        printf("%s\n", pnt < n? "YES": "NO");
    }
    return 0;
}