#include <bits/stdc++.h>

using namespace std;

vector<int> a;

bool can(int x)
{
    int l = 0;
    int r = a.size() - x;
    for (int i = 0; i < x; i++, l++, r++)
        if (a[l] * 2 > a[r])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0;
    int r = n / 2;
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (can(m))
            l = m;
        else
            r = m - 1;
    }
    cout << n - l;

    return 0;
}