#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];
int cnt[Maxn];

bool Solve()
{
    fill(cnt, cnt + n + 1, 0);
    for (int i = 0; i < n; i++) {
        while (a[i] > n) a[i] /= 2;
        cnt[a[i]]++;
    }
    for (int i = n; i > 0; i--)
        if (cnt[i] == 0) return false;
        else cnt[i / 2] += cnt[i] - 1;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}