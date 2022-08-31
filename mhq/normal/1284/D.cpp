#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int n;
void compress(vector < pair < int, int > >& a) {
    vector < int > cords;
    for (auto it : a) {
        cords.push_back(it.first);
        cords.push_back(it.second);
    }
    sort(cords.begin(), cords.end());
    cords.erase(unique(cords.begin(), cords.end()), cords.end());
    for (auto& it : a) {
        it.first = lower_bound(cords.begin(), cords.end(), it.first) - cords.begin() + 1;
        it.second = lower_bound(cords.begin(), cords.end(), it.second) - cords.begin() + 1;
    }
}
vector < pair < int, int > > a;
vector < pair < int, int > > b;
bool t[4 * maxN + 10];
bool lazy[4 * maxN + 10];
void push(int v, int tl, int tr) {
    if (tl == tr) {
        return;
    }
    if (lazy[v]) {
        t[2 * v] = t[2 * v + 1] = true;
        lazy[2 * v] = lazy[2 * v + 1] = true;
    }
    lazy[v] = false;
}
void add(int v, int tl, int tr, int l, int r) {
    if (l > r) return;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (tl == l && tr == r) {
        t[v] = true;
        lazy[v] = true;
        push(v, tl, tr);
        return;
    }
    add(2 * v, tl, tm, l, min(r, tm));
    add(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    t[v] = t[2 * v] | (t[2 * v + 1]);
}
bool ask(int v, int tl, int tr, int l, int r) {
    if (l > r) return false;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (tl == l && tr == r) {
        return t[v];
    }
    return (ask(2 * v, tl, tm, l, min(r, tm)) | ask(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}
void solve() {
    for (int i = 1; i <= 4 * maxN; i++) {
        t[i] = false;
        lazy[i] = false;
    }
    vector < pair < int, int > > events;
    for (int i = 0; i < a.size(); i++) {
        events.emplace_back(a[i].first - 1, i);
        events.emplace_back(a[i].second, ~i);
    }
    sort(events.begin(), events.end());
    set < pair < int, int > > s;
    for (auto it : events) {
        if (it.second < 0) {
            int id = ~it.second;
//            cout << "ADDING " << b[id].first << " " << b[id].second << endl;
            add(1, 1, maxN, b[id].first, b[id].second);
        }
        else {
            int id = it.second;
//            cout << "ASKING " << b[id].first << " " << b[id].second << endl;
            if (ask(1, 1, maxN, b[id].first, b[id].second)) {
                cout << "NO";
                exit(0);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }
    compress(a);
    compress(b);
    solve();
    swap(a, b);
    solve();
    cout << "YES" << '\n';
    return 0;
}