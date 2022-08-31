#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int ASK(const vector < int >& a, const vector < int >& b) {
    vector < int > cnt(n + 1);
    for (int v : a) {
        cnt[v]++;
    }
    for (int v : b) {
        cnt[v]--;
    }
    vector < int > c, d;
    for (int v = 1; v <= n; v++) {
        if (cnt[v] > 0) c.emplace_back(v);
        if (cnt[v] < 0) d.emplace_back(v);
    }
//    assert(c.size() == d.size());
    if (c.empty()) return 0;
    cout << "? " << c.size() << " " << d.size() << endl;
    for (int v : c) cout << v << " ";
    cout << endl;
    for (int v : d) cout << v << " ";
    cout << endl;
    string resp;
    cin >> resp;
    if (resp == "FIRST") return 1;
    else if (resp == "SECOND") return 2;
    else if (resp == "EQUAL") return 0;
    else {
        exit(0);
        return -228;
    }
}
set < int > stones;
bool go(int l, int r) {
    if (r - l + 1 <= stones.size()) {
        vector < int > p1(r - l + 1);
        iota(p1.begin(), p1.end(), l);
        vector < int > p2;
        for (int v : stones) {
            if (p2.size() == p1.size()) break;
            p2.push_back(v);
        }
        if (ASK(p1, p2) == 0) {
            for (int v : p1) {
                stones.insert(v);
            }
            return false;
        }
    }
    if (l == r) {
        cout << "! " << l << endl;
        return true;
    }
    int mid = (l + r) / 2;
    if ((r - l + 1) % 2 == 0) {
        vector<int> p1, p2;
        p1.resize(mid - l + 1);
        iota(p1.begin(), p1.end(), mid - l + 1);
        p2.resize(r - mid);
        iota(p2.begin(), p2.end(), r - mid);
        int c = ASK(p1, p2);
        if (c == 0) {
            if (go(l, mid)) {
                return true;
            }
            if (go(mid + 1, r)) {
                return true;
            }
        }
        for (int v = l; v <= r; v++) {
            stones.insert(v);
        }
        return false;
    }
    else {
        vector<int> p1, p2;
        p1.resize(mid - l + 1);
        iota(p1.begin(), p1.end(), mid - l + 1);
        p2.resize(r - mid + 1);
        iota(p2.begin(), p2.end(), r - mid + 1);
        if (go(l, mid)) {
            return true;
        }
        if (go(mid, r)) {
            return true;
        }
        for (int v = l; v <= r; v++) {
            stones.insert(v);
        }
        return false;
    }
}
const int BUBEN = 20;
mt19937 rnd((int) std::chrono::steady_clock::now().time_since_epoch().count());
int k;
void solve() {
    cin >> n >> k;
    stones.clear();
    int cur_max = 1;
    vector < int > cands(n - 1);
    iota(cands.begin(), cands.end(), 2);
    for (int i = 0; i < BUBEN; i++) {
        if (cands.empty()) break;
        int pos = rnd() % cands.size();
        int t = cands[pos];
        cands.erase(cands.begin() + pos);
        if (ASK({cur_max}, {t}) == 2) cur_max = t;
    }
    stones.insert(cur_max);
    go(1, n);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}