#include <bits/stdc++.h>
using namespace std;

const int Maxn = 150005;

int T;
int n;
int lst[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(lst, lst + Maxn, -1);
        int res = -1;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (lst[a] != -1) res = max(res, lst[a] + n - i);
            lst[a] = i;
        }
        printf("%d\n", res);
    }
    return 0;
}