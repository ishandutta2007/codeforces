#include <iostream>
#include <vector>
#include <map>

using namespace std;

constexpr int N = 1e6, G = 5e5, mod = 1e9 + 7;

int n, m, cl[N], sz[G], g, t, clam = 1;
int64_t ans = 1;
map<int, int> M;
map<pair<int, int>, vector<int>> M2;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> g;
        M.clear();
        while (g--)
            cin >> t, ++M[--t];
        M2.clear();
        for (auto i: M)
            M2[{i.second, cl[i.first]}].push_back(i.first);
        for (auto i: M2)
        {
            for (auto j: i.second)
                cl[j] = clam;
            ++clam;
        }
    }
    for (int i = 0; i < m; ++i)
        ++sz[cl[i]];
    for (int i = 0; i < clam; ++i)
        for (int j = 0; j < sz[i]; ++j)
            (ans *= j + 1) %= mod;
    cout << ans;
    return 0;
}