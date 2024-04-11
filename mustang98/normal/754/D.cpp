#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int inf = 2e9;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vector<pair<int, int> > v;

vector<pair<int, int> > inp;

map<int, int> m;

int main()
{
    int n, k, l, r;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> l >> r;
        v.push_back(make_pair(l, -inf));
        v.push_back(make_pair(r, l));
        inp.push_back(make_pair(l, r));
    }

    sort(v.begin(), v.end());

    int ansl = -inf, ansr = -inf;
    int curans = -1;

    ordered_set os;

    for (int i = 0; i < v.size(); ++i)
    {
        int rr = v[i].first, ll;
        if (os.size() >= k)
        {
            ll = (*os.find_by_order(k - 1)).first;
            if (rr - ll + 1 > curans)
            {
                curans = rr - ll + 1;
                ansl = ll;
                ansr = rr;
            }
        }

        if (v[i].second == -inf)
        {
            if (m.count(v[i].first) == 0)
            {
                m[v[i].first] = 0;
            }
            os.insert(make_pair(v[i].first, m[v[i].first]));
            m[v[i].first]++;
        }
        else
        {
            m[v[i].second]--;
            os.erase(make_pair(v[i].second, m[v[i].second]));
        }

        if (os.size() >= k)
        {
            ll = (*os.find_by_order(k - 1)).first;
            if (rr - ll + 1 > curans)
            {
                curans = rr - ll + 1;
                ansl = ll;
                ansr = rr;
            }
        }
    }

    //std::cout << curans;
    if (curans == -1)
    {
        cout << 0 << endl;
        for (int i = 0; i < k; ++i)
        {
            cout << i + 1 << ' ';
        }
    }
    else
    {
        cout << curans << "\n";
        for (int i = 0; i < inp.size(); ++i)
        {
            if (k == 0) break;
            if (inp[i].first <= ansl && inp[i].second >= ansr)
            {
                cout << i + 1 << ' ';
                k--;
            }
        }
    }


    return 0;
}