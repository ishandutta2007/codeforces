#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll res[Maxn];
int n;
ll tot;

int main()
{
    for (int i = 2; i < Maxn; i++)
        for (int j = i + i; j < Maxn; j += i)
            res[j] += j / i;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        tot += res[i];
    printf("%I64d\n", 4ll * tot);
    return 0;
}