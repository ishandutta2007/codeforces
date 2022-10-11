#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 305;

int n, t, lst, a[N], pre[N];

pair<int, int> ask(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int ret; cin >> ret;
    assert(ret >= 0);
    int msk = 1 << (abs(ret - lst) % 2 == r % 2);
    lst = ret;
    return {ret, msk};
}

int get(int l, int r, bool le)
{
    int len = le ? r : n - l + 1;
    while (true)
    {
        pair<int, int> ans = ask(l, r);
        int msk = ans.se;
        while (ans.se != 0)
            ans.se ^= ask(l, r).se;
        if (msk == (1 << le))
            return (t - ans.fi + len) / 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    lst = t;
    if (n == 1)
        return cout << "! " << t << endl, 0;
    if (n % 2 == 0)
        pre[1] = get(1, 1, true);
    else
        pre[1] = t - get(2, n, false);
    for (int i = 2; i <= n; i++)
        pre[i] = get(i - n % 2, i, true);
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << pre[i] - pre[i - 1];
    cout << endl;
}