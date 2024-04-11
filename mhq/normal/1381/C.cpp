#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, x, y;
const int maxN = 1e5 + 10;
vector < int > where[maxN];
int b[maxN];
int cnt[maxN];
int a[maxN];
int d[maxN];
void solve() {
    cin >> n >> x >> y;
//    n = rand() % 5 + 1;
//    x = rand() % (n + 1);
//    y = rand() % (n + 1);
//    if (x > y) swap(x, y);
//    cout << n << " " << x << " " << y << endl;
    for (int i = 1; i <= (n + 1); i++) {
        where[i].clear();
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = -1;
        cin >> b[i];
//        b[i] = rand() % (n + 1) + 1;
//        cout << b[i] << " ";
        where[b[i]].emplace_back(i);
        cnt[b[i]]++;
    }
//    cout << "--------------" << endl;
    int bad = -1;
    for (int i = 1; i <= (n + 1); i++) {
        if (cnt[i] == 0) {
            bad = i;
        }
    }
    assert(bad > 0);
    int val = (n - x) / 2;
    int need = 0;
    for (int i = 1; i <= (n + 1); i++) {
        if (cnt[i] > val) {
            int add = min(cnt[i] - val, x - need);
            need += add;
            cnt[i] -= add;
            for (int c = 0; c < add; c++) {
                a[where[i].back()] = i;
                where[i].pop_back();
            }
        }
    }
    ll cur_val = 0;
    for (int i = 1; i <= n + 1; i++) {
        cur_val += min(cnt[i], n - x - cnt[i]);
    }
    int still_need = x - need;
    if (cur_val - still_need < (y - x)) {
        cout << "NO\n";
        return;
    }
    else {
        cout << "YES\n";
    }
    if (still_need > 0) {
        for (int i = 1; i <= n + 1; i++) {
            assert(cnt[i] <= val);
            int add = min(cnt[i], still_need);
            for (int c = 0; c < add; c++) {
                a[where[i].back()] = i;
                where[i].pop_back();
            }
            still_need -= add;
            cnt[i] -= add;
        }
        assert(still_need == 0);
    }
    cur_val = 0;
    for (int i = 1; i <= n + 1; i++) {
        cur_val += min(cnt[i], n - x - cnt[i]);
    }
    assert(cur_val >= (y - x));
    int el = y - x;
    for (int i = 1; i <= n + 1; i++) {
        int at_least = min(min(cnt[i], n - x - cnt[i]), el);
        el -= at_least;
        d[i] = at_least;
    }
    assert(el == 0);
    set < pair < int, int > > all;
    set < pair < int, int > > only;
    for (int i = 1; i <= n + 1; i++) {
        if (d[i]) {
            only.insert(make_pair(cnt[i] + d[i], i));
        }
        all.insert(make_pair(cnt[i], i));
    }
//    for (int i = 1; i <= n + 1; i++) {
//        cout << cnt[i] << " " << d[i] << endl;
//    }
    while (!only.empty()) {
        auto it = *(--only.end());
        only.erase(it);
        assert(d[it.second] + cnt[it.second] == it.first);
        auto pit = *(--all.end());
        assert(cnt[pit.second] == pit.first);
        all.erase(pit);
        int our_ind = it.second;
        int his_ind = pit.second;
        if (our_ind == his_ind) {
            assert(!all.empty());
            auto git = *(--all.end());
            all.erase(git);
            his_ind = git.second;
        }
        else {
            all.erase(make_pair(cnt[it.second], it.second));
        }
        assert(cnt[his_ind] > 0);
        a[where[his_ind].back()] = our_ind;
        where[his_ind].pop_back();
        d[our_ind]--;
        if (d[his_ind] > 0) {
            only.erase(make_pair(cnt[his_ind] + d[his_ind], his_ind));
        }
        cnt[his_ind]--;
        for (int v : {our_ind, his_ind}) {
            all.insert(make_pair(cnt[v], v));
            if (d[v]) {
                only.insert(make_pair(d[v] + cnt[v], v));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) a[i] = bad;
        cout << a[i] << " ";
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst = 10000;
    cin >> tst;
    while(tst--) {
        solve();
    }
    return 0;
}