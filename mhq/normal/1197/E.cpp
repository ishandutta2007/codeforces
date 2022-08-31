#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

pair < ll, int > merge(pair < ll, int > a, pair < ll, int > b) {
    if (a.first < b.first) return a;
    else if (a.first > b.first) return b;
    else {
        return {a.first, sum(a.second, b.second)};
    }
}

const int maxN = 2 * (int)1e5 + 100;
pair < ll, int > t[4 * maxN];
bool cmp(pair < int, int >& a, pair < int, int >& b) {
    return a.second < b.second;
}

pair < ll, int > get(int v, int tl, int tr, int l, int r) {
    if (l > r) return make_pair(1e18, 0);
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return merge(get(v + v, tl, tm, l, min(tm, r)), get(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}

void upd(int v, int tl, int tr, int pos, pair < ll, int > val) {
    if (tl == pos && tr == pos) {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(v + v, tl, tm, pos, val);
    else upd(v + v + 1, tm + 1, tr, pos, val);
    t[v] = merge(t[v + v], t[v + v + 1]);
}

pair < int, int > all[maxN];
int sec[maxN];
int fi[maxN];
int n;
int pref_max[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int i = 1; i < 4 * maxN; i++) {
        t[i] = make_pair(1e18, 0);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> all[i].second >> all[i].first;
    }
    sort(all + 1, all + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        sec[i] = all[i].second;
        fi[i] = all[i].first;
        pref_max[i] = max(pref_max[i - 1], fi[i]);
        //cout << fi[i] << " " << sec[i] << endl;
    }
    pair < ll, int > best = make_pair(1e18, 0);
    for (int i = 1; i <= n; i++) {
        int cur = fi[i];
        int id = lower_bound(sec + 1, sec + n + 1, cur + 1) - sec;
        id--;
        int mx = pref_max[id];
        int idL = lower_bound(sec + 1, sec + n + 1, mx + 1) - sec;
        pair < ll, int > our_val;
        if (idL <= id && id != 0) {
            our_val = get(1, 1, n, idL, id);
        }
        else {
            our_val = make_pair(1e18, 0);
        }
        our_val.first += fi[i] - sec[i];
        if (id == 0) {
            pair<ll, int> var = make_pair(fi[i] - sec[i], 1);
            our_val = merge(our_val, var);
        }
        upd(1, 1, n, i, our_val);
        if (sec[i] > pref_max[n]) {
            best = merge(best, {our_val.first + sec[i], our_val.second});
        }
    }
    cout << best.second;
    return 0;
}