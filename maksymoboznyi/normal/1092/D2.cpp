#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a[N], l[N], r[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    stack<pair<int, int> > q;
    for (int i = 1; i <= n; i++)
    {
        while (q.size() > 0 && q.top().first <= a[i])
            q.pop();
        if (q.size() == 0)
            l[i] = 0;
        else
            l[i] = q.top().second;
        q.push({a[i], i});
    }
    while (q.size() > 0)
    q.pop();
    for (int i = n; i > 0; i--)
    {
        while (q.size() > 0 && q.top().first <= a[i])
            q.pop();
        if (q.size() == 0)
            r[i] = n + 1;
        else
            r[i] = q.top().second;
        q.push({a[i], i});
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        if ((r[i] - l[i] - 1) % 2 && (l[i] != 0 || r[i] != n + 1)) {
            cout << "NO";
            return 0;
        }
        cout << "YES";
    return 0;
}