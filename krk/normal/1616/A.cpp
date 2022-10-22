#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int cnt[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(cnt, cnt + Maxn, 0);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            cnt[abs(a)]++;
        }
        int res = cnt[0] > 0;
        for (int i = 1; i < Maxn; i++)
            res += int(cnt[i] > 0) + int(cnt[i] > 1);
        printf("%d\n", res);
    }
    return 0;
}