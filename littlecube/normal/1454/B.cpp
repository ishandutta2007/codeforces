#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<pair<int, int>> v;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            cin >> tmp;
            v.emplace_back(make_pair(tmp, i));
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < n; i++)
        {
            if ((upper_bound(v.begin(), v.end(), v[i], comp) - lower_bound(v.begin(), v.end(), v[i], comp)) == 1)
            {
                cout << v[i].second << '\n';
                break;
            }
            if (i == n - 1)
            {
                cout << "-1\n";
            }
        }
    }
}