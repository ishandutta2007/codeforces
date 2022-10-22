#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
vector <int> res;

bool Solve()
{
    if (n % 2) return false;
    sort(a, a + n);
    res.clear();
    for (int i = 0; i < n / 2; i++) {
        if (a[i] >= a[n / 2 + i] || !res.empty() && a[i] >= res.back())
            return false;
        res.push_back(a[i]);
        res.push_back(a[n / 2 + i]);
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if (!Solve()) { printf("NO\n"); continue; }
        printf("YES\n");
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}