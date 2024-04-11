#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) {cout << (ans) << '\n'; return;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1));
    vector<int> d;
    d.reserve(n * m);
    for (int i = 0; i < n; ++i) {
        auto &row = a[i];
        for (auto &x: row) cin >> x;
        for (int j = 0; j < m; ++j) d.push_back(row[j]);
        sort(row.begin(), row.end() - 1);
    }
    sort(a.begin(), a.end(), [m](auto u, auto v) { return u[m] < v[m]; });
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    for (auto &row: a) for (int j = 0; j < m; ++j) row[j] = lower_bound(d.begin(), d.end(), row[j]) - d.begin();
    vector<vector<int>> setv;
    vector<int> seti;
    setv.reserve(n * ((1 << m) - 1));
    seti.reserve(n * ((1 << m) - 1));
    for (int i = 0; i < n; ++i) {
        for (int mask = 1; mask < (1 << m); ++mask) {
            vector<int> v;
            for (int bit = 0; bit < m; ++bit) if (mask & (1 << bit)) v.push_back(a[i][bit]);
            setv.emplace_back(v);
            seti.emplace_back(i);
        }
    }
    vector<int> ind(setv.size());
    iota(ind.begin(), ind.end(), 0);
    for (int j = 0; j < m; ++j) {
        vector<int> cnt(d.size());
        for (int i = 0; i < ind.size(); ++i) {
            vector<int> &set = setv[i];
            cnt[(j < set.size()) ? set[j] : 0]++;
        }
        for (int i = 1; i < cnt.size(); ++i) cnt[i] += cnt[i - 1];
        vector<int> newInd(ind.size());
        for (int i = ind.size() - 1; i >= 0; --i) {
            vector<int> &set = setv[ind[i]];
            newInd[--cnt[(j < set.size()) ? set[j] : 0]] = ind[i];
        }
        ind = newInd;
    }
    vector<vector<int>> oddInd(n);
    vector<vector<int>> evenInd(n);
    vector<vector<int>> rev(setv.size());
    vector<int> idx(setv.size());
    vector<int> order(setv.size());
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) pos[i] = i * ((1 << m) - 1);
    for (int k = 0; k < ind.size(); ++k) {
        order[pos[seti[k]]++] = k;
        if (k == 0 || setv[ind[k - 1]] != setv[ind[k]]) idx[k] = ind[k]; else idx[k] = idx[k - 1];
    }
    for (int k: order) {
        int i = seti[ind[k]];
        (setv[ind[k]].size() & 1 ? oddInd : evenInd)[i].push_back(idx[k]);
        rev[idx[k]].push_back(i);
    }
    int bestAns = INT_MAX;
    int high = n;
    for (int i = 0; i < n; ++i) {
        auto full = [&](int index) {
            int count = 0;
            for (int idx: oddInd[i]) {
                int local = lower_bound(rev[idx].begin(), rev[idx].end(), index) - rev[idx].begin();
                count += local;
            }
            for (int idx: evenInd[i]) {
                int local = lower_bound(rev[idx].begin(), rev[idx].end(), index) - rev[idx].begin();
                count -= local;
            }
            return count == index;
        };
        if (full(high)) continue;
        for (int p = 1; ; p *= 2) {
            if (p <= high && (p == 1 || !full(high - p + 1))) high -= p;
            else {
                for (p /= 2; p > 0; p /= 2)
                    if (p <= high && !full(high - p + 1)) {
                        high -= p;
                    }
                break;
            }
        }
        if (high > i) bestAns = min(bestAns, a[i][m] + a[high][m]);
    }
    cout << (bestAns > 2e9 ? -1 : bestAns) << '\n';
}