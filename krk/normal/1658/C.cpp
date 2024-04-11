#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int c[Maxn];

bool Solve()
{
    int pnt = 0;
    while (pnt < n && c[pnt] != 1) pnt++;
    if (pnt >= n) return false;
    int mx = 1;
    for (int i = 1; i < n; i++) {
        int ind = (pnt + i) % n;
        if (c[ind] < 2 || c[ind] > mx + 1) return false;
        mx = c[ind];
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}