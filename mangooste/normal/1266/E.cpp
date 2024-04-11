#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

int n;
vector<int> a;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &i : a)
        cin >> i;
    vector<int> cnt(n, 0);
    set<pair<int, int>> setik;
    map<pair<int, int>, int> mapa;
    ll sm = accumulate(all(a), 0LL);
    int q;
    cin >> q;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u, s--, u--;
        if (setik.find({s, t}) != setik.end()) {
            int pos = mapa[{s, t}] - 1;
            if (pos != -1) {
                cnt[pos]--;
                sm += (cnt[pos] < a[pos]);
            }
            if (u != -1) {
                cnt[u]++;
                sm -= (cnt[u] <= a[u]);
            } else
                setik.erase({s, t});
            mapa[{s, t}] = u + 1;
        } else {
            setik.insert({s, t});
            mapa[{s, t}] = u + 1;
            if (u != -1) {
                cnt[u]++;
                sm -= (cnt[u] <= a[u]);
            }
        }
        cout << sm << '\n';
    }
}