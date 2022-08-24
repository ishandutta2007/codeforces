#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e6 + 10;
int n, q;
ll ans[maxN];
int p[maxN];
int le[maxN], ri[maxN];
ll pref[maxN];
int l[maxN], r[maxN];
ll fenw[2][maxN];
void add(int where, int v, int d) {
    while (v <= n) {
        fenw[where][v] += d;
        v = (v | (v - 1)) + 1;
    }
}
ll Get(int where, int r) {
    ll ans = 0;
    while (r > 0) {
        ans += fenw[where][r];
        r = r & (r - 1);
    }
    return ans;
}
ll fenwGet(int where, int l, int r) {
    return Get(where, r) - Get(where, l - 1);
}
vector < int > queryLeft[maxN], queryRight[maxN], valLeft[maxN], valRight[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    stack < pair < int, int > > s;
    s.push(make_pair(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && s.top().first < p[i]) s.pop();
        le[i] = s.top().second + 1;
        s.push(make_pair(p[i], i));
    }
    while (!s.empty()) s.pop();
    s.push(make_pair(n + 1, n + 1));
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && s.top().first < p[i]) s.pop();
        ri[i] = s.top().second - 1;
        s.push(make_pair(p[i], i));
    }
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = ri[i] - le[i] + 1;
        pref[i] += pref[i - 1];
        //cout << le[i] << " " << ri[i] << '\n';
        valLeft[le[i]].push_back(i);
        valRight[ri[i]].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> l[i];
        queryLeft[l[i]].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> r[i];
        ans[i] += pref[r[i]] - pref[l[i] - 1];
        queryRight[r[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int x : valLeft[i]) {
            add(0, x, 1);
            add(1, x, i);
        }
        for (int pos : queryLeft[i]) {
            ans[pos] -= fenwGet(0, l[pos], r[pos]) * l[pos];
            ans[pos] += fenwGet(1, l[pos], r[pos]);
        }
    }
    for (int i = 1; i <= n; i++) {
        fenw[0][i] = fenw[1][i] = 0;
    }
    for (int i = n; i >= 1; i--) {
        for (int x : valRight[i]) {
            add(0, x, 1);
            add(1, x, i);
        }
        for (int pos : queryRight[i]) {
            ans[pos] += fenwGet(0, l[pos], r[pos]) * r[pos];
            ans[pos] -= fenwGet(1, l[pos], r[pos]);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << " ";
    }
}