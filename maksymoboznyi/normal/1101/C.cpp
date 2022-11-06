#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 1e9 + 7;

int kol[3], col[N], n;

struct cell
{
    int pos, num, type;
};

bool cmp(cell a, cell b)
{
    if (a.pos != b.pos)
        return a.pos < b.pos;
    return a.type < b.type;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int o = 0; o < t; o++)
    {
        int n;
        cin >> n;
        vector<cell> v;
        for (int i = 1; i <= n; i++)
        {
            int l, r;
            cin >> l >> r;
            v.pb({l, i, 0});
            v.pb({r, i, 1});
        }
        sort(v.begin(), v.end(), cmp);
        set<int> s;
        bool w = 0;
        for (int i = 1; i <= n; i++)
            col[i] = 0;
        kol[1] = kol[2] = 0;
        for (int i = 0; i < v.size(); i++)
            if (v[i].type == 0)
            {
                s.insert(v[i].num);
                if (s.size() == 1) {
                    col[v[i].num] = 1;
                    kol[1]++;
                    if (kol[1] > 1 && kol[2] == 0 ){
                        kol[1]--;
                        kol[2]++;
                        col[v[i].num] = 2;
                    }
                    continue;
                }
                int a = *s.begin();
                auto it = s.begin();
                it++;
                int b = *it;
                col[v[i].num] = max(col[a], col[b]);
            }
            else
            {
                s.erase(v[i].num);
            }
        if (kol[2] == 0) {
            cout << -1;
        }else
        for (int i = 1; i <= n; i++)
            cout << col[i] << ' ';
        cout << "\n";
    }
    return 0;
}