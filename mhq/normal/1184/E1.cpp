#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxE = (int)1e6 + 100;
int a[maxE], b[maxE], we[maxE];
vector < pair < int, pair < int, int > > > ed;
const int maxN = (int)1e5 + 100;
int p[maxN];
int get(int x) {
    if (x == p[x]) return x;
    p[x] = get(p[x]);
    return p[x];
}
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rand() % 2) swap(a, b);
    p[a] = b;
    return true;
}
bool check(int x) {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int l = 0;
    while (l < ed.size() && ed[l].first < x) {
        unite(ed[l].second.first, ed[l].second.second);
        l++;
    }
    return unite(a[1], b[1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> we[i];
    }
    for (int i = 2; i <= m; i++) {
        ed.emplace_back(make_pair(we[i], make_pair(a[i], b[i])));
    }
    sort(ed.begin(), ed.end());
    int l = 0;
    int r = 1000 * 1000 * 1000;
    if (check(r)) {
        cout << r;
        return 0;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}