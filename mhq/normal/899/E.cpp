#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
int n;
int a[maxN];
set < pair < int, int > > x;
set < pair < int, int > > y;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int curl = 1;
    int cur = a[1];
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] != cur) {
            x.insert(make_pair(-1 * (i - curl), curl));
            y.insert(make_pair(curl, i - curl));
            curl = i;
            cur = a[i];
        }
    }
    int ans = 0;
    while (!x.empty()) {
        ans++;
        auto it = x.begin();
        //cout << (it -> second) << endl;
        int len = -(it -> first);
        int l = it -> second;
        x.erase(it);
        y.erase(make_pair(l, len));
        auto it1 = y.lower_bound(make_pair(l, -1));
        auto it3 = it1;
        if (it1 == y.end() || it1 == y.begin()) continue;
        it1 = it3;
        it1--;
        //cout << (it1 -> first) << endl;
        auto it2 = it1;
        it1 = it3;
        int l1 = it2 -> first;
        int l2 = it1 -> first;
        int len1 = it2 -> second;
        int len2 = it1 -> second;
        if (a[l1] != a[l2]) continue;
        y.erase(make_pair(l1, len1));
        y.erase(make_pair(l2, len2));
        x.erase(make_pair(-len2, l2));
        x.erase(make_pair(-len1, l1));
        x.insert(make_pair(-len1 - len2, l1));
        y.insert(make_pair(l1, len1 + len2));
    }
    cout << ans;
    return 0;
}