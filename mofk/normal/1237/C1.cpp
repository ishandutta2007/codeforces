#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
int n;
set <pair <ii, ii> > s;
const int inf = 1e9;

bool inside(pair <ii, ii> x, pair <ii, ii> y, pair <ii, ii> z) {
    if (x.first.first < min(y.first.first, z.first.first)) return 0;
    if (x.first.first > max(y.first.first, z.first.first)) return 0;
    if (x.second.first < min(y.second.first, z.second.first)) return 0;
    if (x.second.first > max(y.first.first, z.second.first)) return 0;
    if (x.second.second < min(y.second.second, z.second.second)) return 0;
    if (x.second.second > max(y.second.second, z.second.second)) return 0;
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        s.insert({{x, y}, {z, i}});
    }
    while (s.size()) {
        auto it = s.begin();
        int x = (*it).first.first;
        int y = (*it).first.second;
        int z = (*it).second.first;
        int u = (*it).second.second;
        s.erase(it);
        auto jt = s.lower_bound({{x, -inf}, {-inf, -inf}});
        if (jt == s.end()) --jt;
        int nx = (*jt).first.first;
        jt = s.lower_bound({{nx, y}, {-inf, -inf}});
        if (jt == s.end() || (*jt).first.first != nx) --jt;
        int ny = (*jt).first.second;
        jt = s.lower_bound({{nx, ny}, {z, -1}});
        if (jt == s.end() || (*jt).first.first != nx || (*jt).first.second != ny) --jt;
        int v = (*jt).second.second;
        cout << u << ' ' << v << '\n';
        s.erase(jt);
    }
    return 0;
}