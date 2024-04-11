#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> ones, twos, threes;
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            ones.insert(i);
        else if (a[i] == 2)
            twos.insert(i);
        else if (a[i] == 3)
            threes.insert(i);

    set<pii> res;
    vector<int> fix(n, -1);

    int r = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 3) {
            auto fnd1 = ones.lower_bound(i);
            auto fnd2 = twos.lower_bound(i);
            auto fnd3 = threes.upper_bound(i);
            int j1 = fnd1 == ones.end() ? n : *fnd1;
            int j2 = fnd2 == twos.end() ? n : *fnd2;
            int j3 = fnd3 == threes.end() ? n : *fnd3;
            int j = min({j1, j2, j3});
            if (j >= n) {
                cout << "-1\n";
                return 0;
            }
            ones.erase(j);
            twos.erase(j);
            threes.erase(j);
            if (fix[i] == -1) {
                res.insert({r, i});
                res.insert({r, j});
                res.insert({r + 1, j});
                fix[j] = r + 1;
                r += 2;
            } else {
                res.insert({fix[i], i});
                res.insert({fix[i], j});
                res.insert({fix[i] + 1, j});
                fix[j] = fix[i] + 1;
                r = max(r, fix[i] + 2);
            }
        } else if (a[i] == 2) {
            auto fnd = ones.lower_bound(i);
            if (fnd == ones.end()) {
                cout << "-1\n";
                return 0;
            }
            int j = *fnd;
            ones.erase(fnd);
            if (fix[i] == -1) {
                res.insert({r, i});
                res.insert({r, j});
                fix[j] = r;
                r++;
            } else {
                res.insert({fix[i], i});
                res.insert({fix[i], j});
                fix[j] = fix[i];
                r = max(r, fix[i] + 1);
            }
        }
    }

    for (auto i : ones) {
        res.insert({r, i});
        r++;
    }

    for (auto [x, y] : res) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << (int) res.size() << "\n";
    for (auto [x, y] : res) {
        cout << x + 1 << " " << y + 1 << "\n";
    }

    return 0;
}