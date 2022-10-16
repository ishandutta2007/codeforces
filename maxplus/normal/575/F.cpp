#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#define N 5001
#define pb push_back

using namespace std;

int ans[N][2 * N];
int64_t additional[N];
vector<int> sed;
set<int> dump;
int b[N], e[N];

template<class A, class B>
A min(A a, B b)
{
    if (a < b)
        return a;
    return b;
}

int64_t dst(int a, int x, int y)
{
    if (a < x)
        return x - a;
    if (a > y)
        return a - y;
    return 0;
}

int main()
{
    int n, x;
    memset(ans, 63, sizeof(ans));
    memset(additional, 63, sizeof(additional));
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        (cin >> b[i] >> e[i]), dump.insert(b[i]), dump.insert(e[i]);
    dump.insert(x);
    for (auto i: dump)
        sed.pb(i);
    int i = n - 1;
    for (int j = 0; j < sed.size(); ++j)
        ans[i][j] = dst(sed[j], b[i], e[i]);
    for (int j = 0; j < sed.size(); ++j)
        additional[i] = min(additional[i], ans[i][j]);
    for (int j = 0; j < sed.size(); ++j)
        ans[i][j] -= additional[i];
    for (int i = n - 2; i > -1; --i)
    {
        ans[i][0] = dst(sed[0], b[i], e[i]) + ans[i + 1][0];
        for (int j = 1; j < sed.size(); ++j)
            ans[i][j] = min(ans[i][j - 1] + sed[j] - sed[j - 1], dst(sed[j], b[i], e[i]) + ans[i + 1][j]);
        ans[i][sed.size() - 1] = min(ans[i][sed.size() - 1], dst(sed[sed.size() - 1], b[i], e[i]) + ans[i + 1][sed.size() - 1]);
        for (int j = sed.size() - 2; j > -1; --j)
            ans[i][j] = min(ans[i][j], min(ans[i][j + 1] + sed[j + 1] - sed[j], dst(sed[j], b[i], e[i]) + ans[i + 1][j]));
        for (int j = 0; j < sed.size(); ++j)
            additional[i] = min(additional[i], ans[i][j]);
        for (int j = 0; j < sed.size(); ++j)
            ans[i][j] -= additional[i];
    }
    int64_t tans = ans[0][lower_bound(sed.begin(), sed.end(), x) - sed.begin()];
    for (int i = 0; i < n; ++i)
        tans += additional[i];
    cout << tans;
    return 0;
}