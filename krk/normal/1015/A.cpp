#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n, m;
int l[Maxn], r[Maxn];
vector <int> res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &l[i], &r[i]);
    for (int i = 1; i <= m; i++) {
        bool ok = true;
        for (int j = 0; j < n && ok; j++)
            ok = i < l[j] || r[j] < i;
        if (ok) res.push_back(i);
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}