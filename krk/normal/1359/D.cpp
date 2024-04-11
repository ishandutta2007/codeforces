#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int b = -30; b <= 30; b++) {
        int cur = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > b) cur = 0;
            else {
                if (cur < 0) cur = 0;
                cur += a[i];
                res = max(res, cur - b);
            }
    }
    printf("%d\n", res);
    return 0;
}