#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n, INF);
    vector<int> t(m), l(m), r(m), d(m);
    for (int i = 0; i < m; i++)
        cin >> t[i] >> l[i] >> r[i] >> d[i];
    for (int pos = 0; pos < n; pos++)
    {
        long long delta = 0;
        for (int i = 0; i < m; i++)
            if (t[i] == 1)
            {
                if (l[i] <= pos + 1 && pos + 1 <= r[i])
                    delta += d[i];
            }
            else
            {
                if (l[i] <= pos + 1 && pos + 1 <= r[i])
                    a[pos] = min(a[pos], d[i] - delta);
            }
    }
    vector<long long> b = a;
    for (int i = 0; i < m; i++)
        if (t[i] == 1)
        {
            for (int j = l[i] - 1; j < r[i]; j++)
                b[j] += d[i];
        }
        else
        {
            int cur_max = *max_element(b.begin() + l[i] - 1, b.begin() + r[i]);
            if (cur_max != d[i])
            {
                cout << "NO";
                return 0;
            }
        }
    cout << "YES\n";
    for (auto elem: a)
        cout << elem << " ";

    return 0;
}