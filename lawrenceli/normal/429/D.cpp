#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>
#include <vector>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100100;
const ll inf = 1e18;

int n, a[maxn], p[maxn];

ll ans;

bool cmp(pii p1, pii p2) { return p1.B < p2.B; }

ll dist(pii p1, pii p2) { return ll(p1.A - p2.A) * (p1.A - p2.A) + ll(p1.B - p2.B) * (p1.B - p2.B); }

void go(vector<pii> v) {
    if (v.size() <= 1) return;
    sort(v.begin(), v.end());
    vector<pii> v1, v2;
    for (int i = 0; i < v.size() / 2; i++) v1.push_back(v[i]);
    for (int i = v.size() / 2; i < v.size(); i++) v2.push_back(v[i]);

    int x = v[v.size() / 2].A;

    go(v1), go(v2);

    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    vector<pii> w1, w2;
    for (int i = 0; i < v1.size(); i++)
        if (ll(v1[i].A - x) * (v1[i].A - x) < ans)
            w1.push_back(v1[i]);

    for (int i = 0; i < v2.size(); i++)
        if (ll(v2[i].A - x) * (v2[i].A - x) < ans)
            w2.push_back(v2[i]);

    int p = 0;
    for (int i = 0; i < w1.size(); i++) {
        while (p < w2.size() && w2[p].B < w1[i].B) p++;
        for (int j = p - 1; j >= 0 && ll(w2[j].B - w1[i].B) * (w2[j].B - w1[i].B) < ans; j--)
            ans = min(ans, dist(w1[i], w2[j]));

        for (int j = p; j < w2.size() && ll(w2[j].B - w1[i].B) * (w2[j].B - w1[i].B) < ans; j++)
            ans = min(ans, dist(w1[i], w2[j]));
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = i ? p[i - 1] + a[i] : a[i];
    }

    vector<pii> v;
    for (int i = 0; i < n; i++) v.push_back(pii(i, p[i]));
    ans = inf;
    go(v);
    cout << ans << '\n';
}