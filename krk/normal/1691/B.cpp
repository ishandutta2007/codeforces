#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int s[Maxn];
int res[Maxn];

bool Solve()
{
    for (int i = 1, j; i <= n; i = j) {
        j = i;
        while (j <= n && s[i] == s[j]) j++;
        if (j - i == 1) return false;
        for (int l = i; l < j; l++)
            if (l + 1 < j) res[l] = l + 1;
            else res[l] = i;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &s[i]);
        if (Solve())
            for (int i = 1; i <= n; i++)
                printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
        else printf("-1\n");
    }
    return 0;
}