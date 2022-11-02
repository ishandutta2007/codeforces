#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 20) + 10;

int where[N];
bool bad[N];
int cnt[22];
int n, m;
int d;

void addBadMask(int mask)
{
    if (bad[mask])
        return;
    bad[mask] = true;
    for (int bit = 0; bit < m; bit++)
        if (mask & (1 << bit))
            addBadMask(mask ^ (1 << bit));
}

void process()
{
    int mask = 0;
    for (int i = 0; i < m; i++)
        if (!cnt[i])
            mask |= (1 << i);
    addBadMask(mask);
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fill(bad, bad + N, false);
    fill(cnt, cnt + 22, 0);

    cin >> n >> m;
    cin >> d;
    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++)
        {
            int x;
            cin >> x;
            x--;
            where[x] = i;
        }
    }
    for (int i = 0; i < d; i++)
        cnt[where[i]]++;
    process();
    for (int l = 0, r = d; r < n; l++, r++)
    {
        cnt[where[l]]--;
        cnt[where[r]]++;
        process();
    }
    int res = m;
    for (int mask = 0; mask < (1 << m); mask++)
        if (!bad[mask])
            res = min(res, __builtin_popcount(mask));
    cout << res;

    return 0;
}