#include <bits/stdc++.h>

using namespace std;

void pour(int pos, int x, set<int> &q, vector<int> &a)
{
    auto it = q.lower_bound(pos);
    if (it == q.end())
        return;
    pos = *it;
    int add = min(a[pos], x);
    x -= add;
    a[pos] -= add;
    if (a[pos] == 0)
        q.erase(pos);
    if (x)
        pour(pos, x, q, a);
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b = a;
    set<int> q;
    for (int i = 0; i < n; i++)
        q.insert(i);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int p, x;
            cin >> p >> x;
            pour(p - 1, x, q, a);
        }
        else
        {
            int p;
            cin >> p;
            cout << b[p - 1] - a[p - 1] << "\n";
        }
    }

    return 0;
}