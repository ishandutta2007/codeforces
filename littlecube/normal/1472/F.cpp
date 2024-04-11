#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> p;
        vector<pii> v;
        int n, m;
        bool b = true;

        cin >> n >> m;
        v.emplace_back(make_pair(0, 0));

        while (m--)
        {
            int x, y;
            cin >> x >> y;
            if (v[p[y]].first != y)
            {
                p[y] = v.size();
                v.emplace_back(make_pair(y, 1 << (x - 1)));
            }
            else if (v[p[y]].first == y)
            {
                v[p[y]].second |= 1 << (x - 1);
            }
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++)
        {

            if (v[i + 1].second == 3 && (v[i].second == 1 || v[i].second == 2))
            {
                b = false;
                break;
            }
            else if ((v[i + 1].second == 1 && v[i].second == 2) || (v[i + 1].second == 2 && v[i].second == 1))
            {
                if ((v[i + 1].first - v[i].first) % 2 == 0)
                {
                    v[i + 1].second = 3;
                    continue;
                }
                else
                {
                    b = false;
                    break;
                }
            }
            else if ((v[i + 1].second == 1 && v[i].second == 1) || (v[i + 1].second == 2 && v[i].second == 2))
            {
                if ((v[i + 1].first - v[i].first) % 2 == 1)
                {
                    v[i + 1].second = 3;
                    continue;
                }
                else
                {
                    b = false;
                    break;
                }
            }
        }
        if (v.back().second == 1 || v.back().second == 2)
            b = false;

        if (b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}