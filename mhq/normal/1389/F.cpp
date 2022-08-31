#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 4e5 + 10;
int l[maxN], r[maxN], t[maxN];
vector < int > event[maxN];
bool took[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > cords;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> t[i];
        r[i]++;
        t[i]--;
        cords.emplace_back(l[i]);
        cords.emplace_back(r[i]);
    }
    sort(cords.begin(), cords.end());
    cords.erase(unique(cords.begin(), cords.end()), cords.end());
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(cords.begin(), cords.end(), l[i]) - cords.begin();
        r[i] = lower_bound(cords.begin(), cords.end(), r[i]) - cords.begin();
        event[l[i]].emplace_back(i);
        event[r[i]].emplace_back(~i);
    }
    int par = 0;
    set < pair < int, int > > f[2];
    for (int i = 0; i < cords.size(); i++) {
        sort(event[i].begin(), event[i].end());
        for (int v : event[i]) {
            if (v < 0) {
                v = ~v;
                if (took[v]) continue;
                if (!f[t[v] ^ 1].empty()) {
                    auto it = *f[t[v] ^ 1].begin();
                    took[v] = took[it.second] = true;
                    f[t[v] ^ 1].erase(it);
                    f[t[v]].erase(make_pair(r[v], v));
                    par++;
                }
                else {
                    f[t[v]].erase(make_pair(r[v], v));
                }
            }
            else {
                f[t[v]].insert(make_pair(r[v], v));
            }
        }
    }
    cout << n - par;
    return 0;
}