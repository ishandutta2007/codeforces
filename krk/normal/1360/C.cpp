#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cnt[2] = {};
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i] % 2]++;
        }
        sort(a, a + n);
        bool ok = false;
        for (int i = 0; i + 1 < n; i++)
            if (a[i] + 1 == a[i + 1]) ok = true;
        cnt[0] %= 2;
        cnt[1] %= 2;
        if (cnt[0] == 0 && cnt[1] == 0 ||
            cnt[0] == 1 && cnt[1] == 1 && ok)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}