#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl

#include <vector>


struct SNM
{
    std::vector<int> groupID;
    std::vector<std::vector<int>> group;
    std::vector<int> vls;

    SNM(int sz)
    {
        group.resize(sz);
        groupID.resize(sz);
        vls.assign(sz, 0);

        for (int i = 0; i < sz; ++i)
        {
            group[i] = {i};
            groupID[i] = i;
        }
    }

    bool Merge(int id1, int id2, int diff)
    {
        if (groupID[id1] == groupID[id2])
            return (vls[id1]^vls[id2]) == diff;

        int pid1 = id1;
        int pid2 = id2;

        id1 = groupID[id1];
        id2 = groupID[id2];

        if (group[id1].size() < group[id2].size())
        {
            std::swap(id1, id2);
            std::swap(pid1, pid2);
        }

        diff ^= vls[pid1];
        diff ^= vls[pid2];

        for (int i = 0; i < group[id2].size(); ++i)
        {
            int nt2 = group[id2][i];
            groupID[nt2] = id1;
            vls[nt2] ^= diff;
            group[id1].push_back(nt2);
        }

        group[id2] = std::vector<int>();

        return true;
    }
};


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vvi dt(n, vi(n));

    SNM snm(n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dt[i][j];

    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if (dt[i][j] == dt[j][i])
                continue;

            int diff = 0;
            if (dt[j][i] < dt[i][j])
                diff = 1;
            int mn = min(dt[i][j], dt[j][i]);
            int mx = max(dt[i][j], dt[j][i]);

            if (snm.Merge(i, j, diff))
            {
                dt[i][j] = mn;
                dt[j][i] = mx;
            }
            else
            {
                dt[i][j] = mx;
                dt[j][i] = mn;
            }
        }
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << dt[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}