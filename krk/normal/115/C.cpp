#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1000003;
const int Maxd = 4;
const int dh[Maxd] = {0, 0, 1, 1};
const int dv[Maxd] = {0, 1, 1, 0};

int n, m;
vector <pair <int, int> > h, v;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m; cin.ignore();
    h.resize(n); fill(h.begin(), h.end(), make_pair(-1, -1));
    v.resize(m); fill(v.begin(), v.end(), make_pair(-1, -1));
    bool pos = true;
    for (int i = 0; i < n && pos; i++)
        for (int j = 0; j < m && pos; j++) {
            char c; cin >> c;
            if (c == '.') continue;
            int curh = dh[c - '1'], curv = dv[c - '1'];
            if (h[i].first == -1) h[i] = make_pair(j, curh);
            if (v[j].first == -1) v[j] = make_pair(i, curv);
            pos = (h[i].second + j - h[i].first) % 2 == curh &&
                  (v[j].second + i - v[j].first) % 2 == curv;
        }
    if (!pos) cout << "0\n";
    else {
         int res = 1;
         for (int i = 0; i < n; i++)
             if (h[i].first == -1) res = 2 * res % mod;
         for (int i = 0; i < m; i++)
             if (v[i].first == -1) res = 2 * res % mod;
         cout << res << endl;
    }
    return 0;
}