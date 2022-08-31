#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define y1 jlsjkafj
const int maxN = 5005;
typedef bitset < maxN > bs;
bs a[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < pair < int, int >, int > > hor, vert;
    for (int i = 1; i <= n; i++) {
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        if (xa > xb) swap(xa, xb);
        if (ya > yb) swap(ya, yb);
        if (xa == xb) {
            hor.emplace_back(make_pair(ya, yb), xa);
        }
        else {
            vert.emplace_back(make_pair(xa, xb), ya);
        }
    }
    if (hor.size() < vert.size()) swap(hor, vert);
    for (int i = 0; i < vert.size(); i++) {
        for (int j = 0; j < hor.size(); j++) {
            if (hor[j].second < vert[i].first.first || hor[j].second > vert[i].first.second) continue;
            if (vert[i].second < hor[j].first.first || vert[i].second > hor[j].first.second) continue;
            a[i][j] = true;
        }
    }
    ll ans = 0;
    for (int i = 0; i < vert.size(); i++) {
        for (int j = i + 1; j < vert.size(); j++) {
            int sz = (a[i] & a[j]).count();
            ans += (1LL * sz * (sz - 1)) / 2;
        }
    }
    cout << ans;
    return 0;
}