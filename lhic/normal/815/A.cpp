#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n, m;
int g[120][120];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j) {
            if (g[i][j] != g[i][0] + g[0][j] - g[0][0]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    vector<pair<int, int> > vv;
    if (n > m) {
        for (int i = 0; i < m; ++i) {
            int mn = 1000;
            for (int j = 0; j < n; ++j)
                mn = min(mn, g[j][i]);
            for (int j = 0; j < n; ++j)
                g[j][i] -= mn;
            for (int j = 0; j < mn; ++j)
                vv.push_back(make_pair(1, i));
        }
        for (int i = 0; i < n; ++i) {
            int mn = 1000;
            for (int j = 0; j < m; ++j)
                mn = min(mn, g[i][j]);
            for (int j = 0; j < m; ++j)
                g[i][j] -= mn;
            for (int j = 0; j < mn; ++j)
                vv.push_back(make_pair(0, i));
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            int mn = 1000;
            for (int j = 0; j < m; ++j)
                mn = min(mn, g[i][j]);
            for (int j = 0; j < m; ++j)
                g[i][j] -= mn;
            for (int j = 0; j < mn; ++j)
                vv.push_back(make_pair(0, i));
        }
        for (int i = 0; i < m; ++i) {
            int mn = 1000;
            for (int j = 0; j < n; ++j)
                mn = min(mn, g[j][i]);
            for (int j = 0; j < n; ++j)
                g[j][i] -= mn;
            for (int j = 0; j < mn; ++j)
                vv.push_back(make_pair(1, i));
        }
    }
    cout << vv.size() << "\n";
    for (int i = 0; i < vv.size(); ++i) {
        if (vv[i].first == 0)
            printf("row %d\n", vv[i].second + 1);
        else
            printf("col %d\n", vv[i].second + 1);
    }
    return 0;
}