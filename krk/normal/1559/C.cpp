#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int pnt = 1;
        while (pnt <= n && a[pnt] == 0) pnt++;
        vector <int> res;
        for (int i = 1; i < pnt; i++)
            res.push_back(i);
        res.push_back(n + 1);
        if (pnt <= n)
            for (int i = pnt; i <= n; i++)
                res.push_back(i);
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}