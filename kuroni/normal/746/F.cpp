#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, w, k, ans = 0, cur = 0, ret = 0, a[N], b[N];
multiset<int, greater<int>> fi, se;

void add(int u)
{
    fi.insert(u); cur += (u + 1) / 2;
    if (fi.size() > w)
    {
        u = *fi.rbegin();
        fi.erase(fi.find(u)); cur -= (u + 1) / 2;
        se.insert(u); cur += u;
    }
}

void remove(int u)
{
    if (fi.find(u) != fi.end())
    {
        fi.erase(fi.find(u)); cur -= (u + 1) / 2;
        if (!se.empty())
        {
            u = *se.begin();
            se.erase(se.begin()); cur -= u;
            fi.insert(u); cur += (u + 1) / 2;
        }
    }
    else if (se.find(u) != se.end())
    {
        se.erase(se.find(u)); cur -= u;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w >> k;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, pt = 1; i <= n; i++)
    {
        pt = max(pt, i);
        while (pt <= n)
        {
            add(a[pt]);
            if (cur <= k)
                ret += b[pt++];
            else
            {
                remove(a[pt]);
                break;
            }
        }
        ans = max(ans, ret);
        if (pt > i)
        {
            remove(a[i]); ret -= b[i];
        }
        else
            pt = i + 1;
    }
    cout << ans;
}