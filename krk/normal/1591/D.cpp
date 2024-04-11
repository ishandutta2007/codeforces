#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int T;
int n;
int a[Maxn];
int cnt[Maxn];
int BIT[Maxn];

void Insert(int x)
{
    for (int i = x; i > 0; i -= i & -i)
        BIT[i]++;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i <= n; i += i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        bool ok = true;
        for (int i = 0; i + 1 < n && ok; i++)
            ok = a[i] <= a[i + 1];
        if (ok) { printf("YES\n"); continue; }
        if (n < 3) { printf("NO\n"); continue; }
        fill(cnt, cnt + n + 1, 0);
        fill(BIT, BIT + n + 1, 0);
        bool sam = false;
        int inv = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]]++) sam = true;
            inv = (inv + Get(a[i])) % 2;
            Insert(a[i]);
        }
        printf("%s\n", sam || inv % 2 == 0? "YES": "NO");
    }
    return 0;
}