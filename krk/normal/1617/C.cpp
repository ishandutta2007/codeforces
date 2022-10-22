#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int cnt[Maxn], add[Maxn];
int res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(cnt, cnt + n + 1, 0);
        fill(add, add + n + 1, 0);
        int sav = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] <= n) cnt[a[i]]++;
            else { res++; add[min(n, (a[i] - 1) / 2)]++; }
        }
        bool fall = false;
        for (int i = n; i > 0; i--) {
            sav += add[i];
            if (cnt[i] == 0)
                if (sav > 0) sav--;
                else { fall = true; break; }
            else for (int j = 0; j < cnt[i] - 1; j++) {
                res++; add[(i - 1) / 2]++;
            }
        }
        printf("%d\n", fall? -1: res);
    }
    return 0;
}