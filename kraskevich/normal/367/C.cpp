#include <bits/stdc++.h>

using namespace std;

long long edges(long long v)
{
    if (v % 2)
        return v * (v - 1) / 2;
    else
        return v * (v - 1) / 2 + (v - 2) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long n, m;
    cin >> n >> m;
    vector<long long> w(m);
    for (int i = 0; i < m; i++)
    {
        int foo;
        cin >> foo >> w[i];
    }
    long long d = 0;
    while (edges(d + 1) <= n - 1)
        d++;
    sort(w.rbegin(), w.rend());
    long long res = 0;
    for (int i = 0; i < min(d, m); i++)
        res += w[i];
    cout << res;

    return 0;
}