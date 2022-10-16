#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()

using namespace std;

constexpr int N = 1e3;

int a[N][N];

vector<int> c[N], r[N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
        cin >> a[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            r[i].push_back(a[i][j]);
        sort(all(r[i]));
        r[i].resize(unique(all(r[i])) - r[i].begin());
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i)
            c[j].push_back(a[i][j]);
        sort(all(c[j]));
        c[j].resize(unique(all(c[j])) - c[j].begin());
    }
    for (int i = 0; i < n; ++i, cout << '\n')
    for (int j = 0; j < m; ++j)
        cout <<
                max(
                        lower_bound(all(r[i]), a[i][j]) - r[i].begin(),
                        lower_bound(all(c[j]), a[i][j]) - c[j].begin()
                ) +
                max(
                        r[i].end() - lower_bound(all(r[i]), a[i][j]),
                        c[j].end() - lower_bound(all(c[j]), a[i][j])
                ) << ' ';
    return 0;
}