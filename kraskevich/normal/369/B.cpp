#include <bits/stdc++.h>

using namespace std;

bool can(int l, int r, int cnt, int sum)
{
    int low = l * cnt;
    int high = r * cnt;
    return low <= sum && sum <= high;
}

vector<int> build(int l, int r, int cnt, int sum)
{
    //cerr << sum << endl;
    vector<int> res;
    for (int i = 0; i < cnt; i++)
    {
        int cur = l;
        while (cur < r)
        {
            int f = cur + 1;
            int r = sum - f;
            int lo = (cnt - i - 1) * l;
            if (r >= lo)
                cur++;
            else
                break;
        }
        res.push_back(cur);
        sum -= res.back();
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k, l, r, sall, sk;
    cin >> n >> k >> l >> r >> sall >> sk;
    for (int bod = l; bod <= r; bod++)
        if (can(bod, r, k, sk) && can(l, bod, n - k, sall - sk))
        {
            vector<int> f = build(bod, r, k, sk);
            for (auto x : f)
                cout << x << " ";
            f = build(l, bod, n - k, sall - sk);
            for (auto x : f)
                cout << x << " ";
            return 0;
        }

    return 0;
}