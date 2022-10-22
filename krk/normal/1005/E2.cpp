#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int nil = 200015;

int n, m;
int a[Maxn];
int BIT[Maxn];

int Get(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Insert(int x)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i]++;
}

ll Solve(ll m)
{
    fill(BIT, BIT + Maxn, 0);
    int cur = 0; Insert(nil + cur);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= m) cur++;
        else cur--;
        res += Get(cur - 1 + nil);
        Insert(nil + cur);
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ll res = Solve(m) - Solve(m + 1);
    cout << res << endl;
    return 0;
}