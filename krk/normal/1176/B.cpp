#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int cnt[3];

int main()
{
    scanf("%d", &t);
    while (t--) {
        fill(cnt, cnt + 3, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            cnt[a % 3]++;
        }
        int res = cnt[0];
        int tk = min(cnt[1], cnt[2]);
        res += tk; cnt[1] -= tk; cnt[2] -= tk;
        res += cnt[1] / 3 + cnt[2] / 3;
        printf("%d\n", res);
    }
    return 0;
}