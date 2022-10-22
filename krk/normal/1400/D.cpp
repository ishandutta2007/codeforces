#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3005;

int T;
int n;
int a[Maxn];
int cnt[Maxn][Maxn];
ll res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cnt[i][j] = 0;
        res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++)
                res += cnt[a[i]][a[j]];
            for (int j = 1; j < i; j++)
                cnt[a[j]][a[i]]++;
        }
        printf("%I64d\n", res);
    }
    return 0;
}