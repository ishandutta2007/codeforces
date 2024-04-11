#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const int max_n = 200005;
ll inf = 1e10+7;


pair<int, int> m[max_n];

vector<int> z;

ll check(int v)
{
    ll ans = 0;
    for (int i = 0; i < z.size() - 1; i++)
    {
        int d = z[i + 1] - z[i];
        if (v < d)
        {
            return inf;
        }
        int y = v - d;
        int x = d - y;
        if (y >= d) ans += d;
        else ans += y + 2 * x;
    }

    return ans;
}

int main()
{
    int a, b, n, k, s, t;
    cin >> n >> k >> s >>t;
    z.push_back(0);
    for (int i = 0; i < n;i++)
    {
        scanf("%d %d", &m[i].second, &m[i].first);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a);
        z.push_back(a);
    }
    z.push_back(s);
    sort(m, m + n);
    sort(z.begin(), z.end());
    //cout << check(7) << endl;
    ll minv;
    int l = 0, r = n - 1;
    int t1;
    if (check(m[0].first) <= t)
    {
        minv = m[0].first;
    }
    else if (check(m[n - 1].first) > t)
    {
        cout << "-1";
        return 0;
    }
    else
    {
        while (l < r - 1)
        {
            int mid = (l + r)/ 2;
            if (check(m[mid].first) <= t)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        minv = m[r].first;
    }
    ll ans = 1e10;
    for (int i = 0; i < n; i++)
    {
        if (m[i].first >= minv)
        {
            ans = min(ans, (ll)m[i].second);
        }
    }
    cout << ans;
}