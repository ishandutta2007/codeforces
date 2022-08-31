#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2005;
typedef bitset < maxN > bs;
int n, q, m;
bs to_l[maxN];
bs row[maxN];
int bits[maxN];

void flip(int a, int l, int r) {
    bs need = to_l[r] ^ to_l[l - 1];
    row[a] ^= need;
    bits[a] = row[a].count();
}

void print(int rowA, int rowB) {
    if (rowA > rowB) swap(rowA, rowB);
    int c1 = (row[rowA] ^ (row[rowB] & row[rowA]))._Find_first();
    int c2 = (row[rowB] ^ (row[rowA] & row[rowB]))._Find_first();
    if (c1 > c2) swap(c1, c2);
    cout << rowA << " " << c1 << " " << rowB << " " << c2 << '\n';
}

set < pair < int, int > > bad;
set < pair < int, int > > s;

vector < int > his_pairs[maxN];

bool cmp(int x, int y) {
    return make_pair(bits[x], x) < make_pair(bits[y], y);
}

void add(int a, int b) {
    bs f = row[a] ^ (row[a] & row[b]);
    if (f.count() != 0) {
        his_pairs[a].push_back(b);
        his_pairs[b].push_back(a);
        bad.insert(make_pair(a, b));
    }
}

void upd(int v, int l, int r) {
    for (auto it : his_pairs[v]) {
        his_pairs[it].erase(find(his_pairs[it].begin(), his_pairs[it].end(), v));
        if (cmp(v, it)) {
            bad.erase(make_pair(v, it));
        }
        else {
            bad.erase(make_pair(it, v));
        }
    }
    his_pairs[v].clear();
    auto it1 = s.lower_bound(make_pair(bits[v], v));
    if (it1 != s.begin() && it1 != s.end()) {
        auto it2 = it1;
        --it2;
        auto it3 = it1;
        it3++;
        if (it3 != s.end()) {
            pair<int, int> t1 = *it2;
            pair<int, int> t2 = *it3;
            assert(cmp(t1.second, t2.second));
            add(t1.second, t2.second);
        }
    }
    assert(s.find(make_pair(bits[v], v)) != s.end());
    s.erase(s.find(make_pair(bits[v], v)));
    flip(v, l, r);
    s.insert(make_pair(bits[v], v));
    auto it4 = s.lower_bound(make_pair(bits[v], v));
    if (it4 != s.begin()) {
        auto it5 = it4;
        --it5;
        add(it5 -> second, v);
    }
    auto it6 = s.upper_bound(make_pair(bits[v], v));
    if (it6 != s.end()) {
        add(v, it6 -> second);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        to_l[i] = to_l[i - 1];
        to_l[i][i] = true;
    }
    for (int i = 1; i <= n; i++) {
        s.insert(make_pair(bits[i], i));
    }
    while (q--) {
        int a, l, r;
        cin >> a >> l >> r;
        upd(a, l, r);
        if (bad.empty()) {
            cout << -1 << '\n';
        }
        else {
            auto it = bad.begin();
            print(it -> first, it -> second);
        }
    }

    return 0;
}