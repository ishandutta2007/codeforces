#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200005, MX = 500005;

int n, q, x, a[N], pr[MX], cnt[MX];
long long ans = 0;
bool chk[N];
vector<int> ve;

void init()
{
    for (int i = 2; i < MX; i++)
        if (pr[i] == 0)
            for (int j = i; j < MX; j += i)
                pr[j] = i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        cin >> x;
        ve.clear();
        int u = a[x];
        while (u != 1)
        {
            int d = pr[u];
            ve.push_back(d);
            while (u % d == 0)
                u /= d;
        }
        for (int msk = 0; msk < (1 << ve.size()); msk++)
        {
            int cur = 1;
            for (int j = 0; j < (int)ve.size(); j++)
                if (msk >> j & 1)
                    cur *= ve[j];
            if (chk[x])
            {
                cnt[cur]--;
                ans -= cnt[cur] * ((__builtin_popcount(msk) & 1) ? -1 : 1);
            }
            else
            {
                ans += cnt[cur] * ((__builtin_popcount(msk) & 1) ? -1 : 1);
                cnt[cur]++;
            }
        }
        chk[x] = !chk[x];
        cout << ans << '\n';
    }
}