#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
int a[Maxn];
vector <int> res;
int has[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= k; i++)
            has[i - 1] = a[i] - a[i - 1];
        bool ok = true;
        for (int i = k + 1; i <= n && ok; i++)
            ok = has[(i - 1) % k] == a[i] - a[i - 1];
        if (ok) res.push_back(k);
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}