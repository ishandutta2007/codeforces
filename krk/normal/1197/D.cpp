#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 11;
const ll Inf = 4000000000000000000ll;
const int Maxn = 300005;

int n, m, k;
int a[Maxn];
ll mn[Maxm];
ll sub[Maxm];
ll res;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        mn[i] = Inf;
    mn[0] = 0; sub[0] += k;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        for (int j = 0; j < m; j++)
            res = max(res, sum - (mn[j] + sub[j]));
        mn[i % m] = min(mn[i % m], sum - sub[i % m]);
        sub[i % m] += k;
    }
    cout << res << endl;
    return 0;
}