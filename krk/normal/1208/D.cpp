#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll s[Maxn];
ll BIT[Maxn];
int res[Maxn];

void Insert(int ind, ll val)
{
    for (int i = ind; i <= n; i += i & -i)
        BIT[i] += val;
}

ll Get(int ind)
{
    ll res = 0;
    for (int i = ind; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    set <int> S;
    for (int i = 1; i <= n; i++) {
        Insert(i, i);
        S.insert(i);
    }
    for (int i = 0; i < n; i++)
        scanf("%I64d", &s[i]);
    for (int i = n - 1; i >= 0; i--) {
        int lef = 1, rig = n;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Get(mid - 1) >= s[i]) rig = mid - 1;
            else lef = mid + 1;
        }
        set <int>::iterator it = S.lower_bound(rig + 1);
        res[i] = *it; Insert(*it, -res[i]);
        S.erase(it);
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}