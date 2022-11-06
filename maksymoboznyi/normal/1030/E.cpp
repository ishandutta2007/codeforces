#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 6e5 + 5;
const long long inf = 2e18;

int n, a[N], s[N], t1[2*N], t2[2*N];


struct tree
{
    int max, s;
};

int kol(int x)
{
    int res = 0;
    while (x != 0)
    {
        res += x % 2;
        x /= 2;
    }
    return res;
}

void build_max(int v, int vl, int vr)
{
    if (vl == vr)
    {
        t1[v] = a[vl];
        return;
    }
    int vm = (vl + vr)/ 2;
    build_max(v + v, vl, vm);
    build_max(v + v + 1, vm + 1, vr);
    t1[v] = max(t1[v + v], t1[v + v + 1]);
}

void build_kol(int v, int vl, int vr)
{
    if (vl == vr)
    {
        t2[v] = ((s[vl] % 2) == 0);
        return;
    }
    int vm = (vl + vr)/ 2;
    build_kol(v + v, vl, vm);
    build_kol(v + v + 1, vm + 1, vr);
    t2[v] = t2[v + v] + t2[v + v + 1];
}

int get_max(int v, int vl, int vr, int l, int r)
{
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t1[v];
    int vm = (vl + vr) / 2;
    return max(get_max(v + v, vl, vm, l, min(r, vm)), get_max(v + v + 1, vm + 1, vr, max(l, vm + 1), r));
}


int get_kol(int v, int vl, int vr, int l, int r)
{
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t2[v];
    int vm = (vl + vr) / 2;
    return get_kol(v + v, vl, vm, l, min(r, vm)) +  get_kol(v + v + 1, vm + 1, vr, max(l, vm + 1), r);
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = kol(x);
        s[i] = s[i - 1] + a[i];
    }
    build_max(1, 1, n);
    build_kol(1, 1, n);
    int ans = 0;
    ///for <= 100
    for (int l = 1; l<= n; l++)
    {
        int m = 0;
        for (int len  = 1; len <= 65; len ++)
        {
            int r = len + l - 1;
            if (r > n)
                break;
            m = max(m, a[l + len - 1]);
            if ((s[r] - s[l - 1]) % 2 == 0)
                if (m * 2 <= s[r] - s[l - 1])
                    ans++;
        }
    }
    ///for > 100
    for (int l = 1; l <= n; l++)
    {
        if (l + 65 > n)
            continue;
        int k = get_kol(1, 1, n, l + 65, n);
        if (s[l - 1] % 2 == 1)
            k = (n - l - 64) - k;
        ans += k;
    }
    cout << ans;
    return 0;
}