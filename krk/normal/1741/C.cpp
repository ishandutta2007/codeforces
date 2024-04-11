#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n;
int a[Maxn];

int Get(int x)
{
    int res = 0;
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cnt++; sum += a[i];
        if (sum > x) return Maxn;
        if (sum == x) { res = max(res, cnt); cnt = 0; sum = 0; }
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int res = n;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += a[i];
            if (sum % cur == 0)
                res = min(res, Get(cur));
        }
        printf("%d\n", res);
    }
    return 0;
}