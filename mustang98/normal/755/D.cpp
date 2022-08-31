#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000009;

ll tree[max_n * 4] = {0};

void update(int cur, int l, int r, int pos)
{
    if (l == r)
    {
        tree[cur]++;
        return;
    }
    int mid = (l + r)/ 2;
    if (pos <= mid)
    {
        update(cur * 2, l, mid, pos);
    }
    else
    {
        update(cur * 2 + 1, mid + 1, r, pos);
    }
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}

ll get_sum(int cur, int l, int r, int sl, int sr)
{
    if (l == sl && r == sr)
    {
        return tree[cur];
    }

    if (sr < l || sl > r)
    {
        return 0;
    }

    int mid = (l + r) / 2;
    return get_sum(cur * 2, l, mid, sl, min(mid, sr)) +
           get_sum(cur * 2 + 1, mid + 1, r, max(mid + 1, sl), sr);
}

int main()
{
    int n, k;
    cin >> n >> k;
    if (k > n / 2)
    {
        k = n - k;
    }
    int cur = 0;
    ll ans = 1;
    for (int i = 0; i < n; ++i)
    {
        int next = (cur + k);
        if (next >= n)
        {
            next -= n;
        }
        update(1, 0, n - 1, cur);
        update(1, 0, n - 1, next);
        int scur = cur + 1;
        int snext = cur + k - 1;
        if (scur >= n)
        {
            scur -= n;
        }
        if (snext >= n)
        {
            snext -=n;
        }
        if (snext >= scur)
        {
            ans += 1 + get_sum(1, 0, n - 1, scur, snext);
        }
        else
        {
            ans += 1 + get_sum(1, 0, n - 1, scur, n - 1) + get_sum(1, 0, n - 1, 0, snext);
        }
        printf("%I64d ", ans);
        cur = next;
    }
    return 0;
}