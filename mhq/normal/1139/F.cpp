#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int n, m;
int p[maxN], s[maxN], b[maxN], inc[maxN], pref[maxN];
vector < pair < int, int > > cordX;
int idD[maxN], idP[maxN];
vector < int > allFenw[2 * maxN];
int val[maxN];
struct Fenw{
    int n;
    vector < int > f;
    Fenw(int nn) {
        n = nn + 1;
        f.resize(n + 1);
    }
    Fenw() {
        n = 1;
    }
    void addFenw(int pos) {
        while (pos <= n) {
            f[pos]++;
            pos = (pos | (pos - 1)) + 1;
        }
    }
    int getFenw(int x) {
        int ans = 0;
        while (x > 0) {
            ans += f[x];
            x = x & (x - 1);
        }
        return ans;
    }
};
Fenw t[4 * maxN];
vector < int > allPts[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        allPts[v].emplace_back(val[tl]);
        t[v] = Fenw(allPts[v].size());
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    merge(allPts[v*2].begin(), allPts[v*2].end(), allPts[v*2+1].begin(), allPts[v*2+1].end(),
                       back_inserter (allPts[v]));
    t[v] = Fenw(allPts[v].size());
}
void add(int v, int tl, int tr, int pos) {
    auto it = lower_bound(allPts[v].begin(), allPts[v].end(), val[pos]) - allPts[v].begin() + 1;
    t[v].addFenw(it);
    if (tl == tr) return ;
    int tm = (tl + tr) / 2;
    if (pos <= tm) add(v + v, tl, tm, pos);
    else add(v + v + 1, tm + 1, tr, pos);
}
int get(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        if (allPts[v].empty()) return 0;
        auto it = upper_bound(allPts[v].begin(), allPts[v].end(), val) - allPts[v].begin() + 1;
        return t[v].getFenw(it - 1);
    }
    int tm = (tl + tr) / 2;
    return get(v + v, tl, tm, l, min(r, tm), val) + get(v + v + 1, tm + 1, tr, max(l, tm + 1), r, val);
}
int ans[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        all.emplace_back(s[i], m + i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cordX.emplace_back(make_pair(b[i] + p[i], i));
    }

    for (int i = 1; i <= m; i++) {
        cin >> inc[i];
        all.emplace_back(inc[i], i);
     //   cordX.emplace_back(inc[i] + pref[i]);
    }

    for (int i = 1; i <= m; i++) {
        cin >> pref[i];
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    sort(cordX.begin(), cordX.end());
    for (int i = 0; i < n; i++) {
        idD[cordX[i].second] = i + 1;
        val[i + 1] = p[cordX[i].second] - b[cordX[i].second];
    }
    build(1, 1, n);
    for (auto it : all) {
        int id = it.second;
        if (id <= m) {
            int what = inc[id] + pref[id];
            if (cordX[0].first > what) continue;
            int x = lower_bound(cordX.begin(), cordX.end(), make_pair(what + 1, -1)) - cordX.begin() + 1;
            // x - 1
            ans[id] = get(1, 1, n, 1, x - 1, inc[id] - pref[id]);
        }
        else {
            add(1, 1, n, idD[id - m]);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}