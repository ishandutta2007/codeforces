#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];
    vector<int> col(2 * n);
    int res = 0;
    for (int d1 = 1; d1 <= n; d1++)
    {
        map<int, int> cnt;
        for (int i = 0; i < 2 * n; i++)
            cnt[a[i]]++;
        vector<int> t(2 * n, 0);
        set<int> u;
        for (int i = 0; i < d1; i++)
        {
            int best = -1;
            for (int j = 0; j < 2 * n; j++)
                if (t[j] == 0 && !u.count(a[j]))
                    if (best == -1 || cnt[a[best]] < cnt[a[j]])
                        best = j;
            if (best == -1)
                break;
            t[best] = 1;
            u.insert(a[best]);
            cnt[a[best]]--;
        }
        if (u.size() < d1)
            continue;
        int cntB = 0;
        set<int> u1;
        for (int i = 0; i < 2 * n; i++)
            if (t[i] == 0 && cntB < n && !u1.count(a[i]))
            {
                u1.insert(a[i]);
                cntB++;
                t[i] = 2;
            }
        for (int i = 0; i < 2 * n; i++)
            if (t[i] == 0)
                if (cntB < n)
                {
                    t[i] = 2;
                    cntB++;
                }
                else
                {
                    t[i] = 1;
                }
        int cur = u.size() * u1.size();
        if (cur > res)
        {
            res = cur;
            col = t;
        }
    }
    cout << res << endl;
    for (auto elem: col)
        cout << elem << " ";

    return 0;
}