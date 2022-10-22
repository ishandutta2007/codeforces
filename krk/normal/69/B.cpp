#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 101;

int n, m, c[Maxn], res;
vector <pair <int, int> > best[Maxn];

int main()
{
    int l, r, t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> t >> c[i];
        for (int j = l; j <= r; j++) best[j].push_back(make_pair(t, i));
    }
    for (int i = 1; i <= n; i++) if (best[i].size()) {
        sort(best[i].begin(), best[i].end());
        res += c[best[i][0].second];
    }
    cout << res << endl;
    return 0;
}