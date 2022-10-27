#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

bool query(vector<int> v) {
    cout << "? " << v.size() << ' ';
    for (int x: v) cout << x << ' ';
    cout << endl;
    string s;
    cin >> s;
    return s == "YES";
}

void guess(int x) {
    cout << "! " << x << endl;
    string s;
    cin >> s;
    if (s == ":)") exit(0);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    while (a.size() > 3) {
        vector<int> u, v;
        for (int i = 0; i < a.size(); ++i) {
            if (i % 2 == 0) u.push_back(a[i]);
            if (i % 4 != 0 && i % 4 != 3) v.push_back(a[i]);
        }
        int ua = query(u), va = query(v);
        vector<int> b;
        for (int i = 0; i < a.size(); ++i) {
            if ((i % 2 == 0) == ua || (i % 4 != 0 && i % 4 != 3) == va) b.push_back(a[i]);
        }
        a = b;
    }
    if (a.size() <= 2) {
        guess(a[0]);
        guess(a[1]);
    }
    assert(a.size() == 3);
    vector<vector<int>> sets{{0, 1},
                             {1, 2},
                             {1, 2},
                             {0, 1}};
    vector<int> answers;
    for (auto set: sets) answers.push_back(query({a[set[0]], a[set[1]]}));
    int q = 0;
    for (int mask = 0; mask < 16; ++mask) {
        bool bad = false;
        for (int bit = 0; bit < 3; ++bit) if ((mask & (1 << bit)) && (mask & (1 << bit + 1))) bad = true;
        if (bad) continue;
        vector<bool> is(3), no(3);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j) {
                if (((mask >> i) & 1) ^ answers[i] ^ find(sets[i].begin(), sets[i].end(), j) != sets[i].end())
                    no[j] = true;
            }
        {
            for (int i = 0; i < 3; ++i) if (!no[i]) q |= 1 << i;
        }
    }
    assert(q != 7);
    for (int bit = 0; bit < 3; ++bit) if (q & (1 << bit)) guess(a[bit]);
}