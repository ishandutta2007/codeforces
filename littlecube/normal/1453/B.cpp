#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, r = 0, s = 0;
        vector<ll> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            v.emplace_back(tmp);
        }
        for (int i = 1; i < n; i++)
            r += abs(v[i] - v[i - 1]);
        s = max(s, abs(v[1] - v[0]));
        s = max(s, abs(v[n - 1] - v[n - 2]));
        for (int i = 1; i < n - 1; i++)
        {
            if (!((v[i - 1] <= v[i] && v[i] <= v[i + 1]) || (v[i - 1] >= v[i] && v[i] >= v[i + 1])))
                s = max(s, 2 * min(abs(v[i] - v[i - 1]), abs(v[i] - v[i + 1])));
        }
        cout << r - s << '\n';
    }
}