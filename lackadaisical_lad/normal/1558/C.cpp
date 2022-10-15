#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T, typename S = istream>
void read(vector<T>& vec, S& in = cin) {
    for (auto& elem : vec) {
        in >> elem;
    }
}

template <typename T, typename S = ostream>
void write(const vector<T>& vec, char delim = ' ', char last = '\n', S& out = cout) {
    bool first = true;
    for (auto& elem : vec) {
        if (!first) {
            out << delim;
        }
        out << elem;
        first = false;
    }
    out << last;
}

const int MOD = 1e9 + 7;

ll binpow(ll a, ll p, ll mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * a % mod;
        }
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != (i + 1) % 2) {
            cout << "-1\n";
            return;
        }
    }

    auto findPos = [&](int val) {
        for (int i = 0; i < n; i++) {
            if (a[i] == val) {
                return i;
            }
        }
        return -1;
    };

    vector<int> ops;
    for (int i = 2; i < n; i += 2) {
        int posOdd = findPos(i + 1);
        if (posOdd) {
            ops.push_back(posOdd + 1);
            reverse(a.begin(), a.begin() + posOdd + 1);
        }
        int posEven = findPos(i);
        if (posEven > 1) {
            ops.push_back(posEven);
            reverse(a.begin(), a.begin() + posEven);   
        }
    }

    for (int i = 2; i < n; i += 2) {
        int posOdd = findPos(i - 1);
        if (posOdd) {
            ops.push_back(posOdd + 1);
            reverse(a.begin(), a.begin() + posOdd + 1);
        }
        int posEven = findPos(i);
        if (posEven > 1) {
            ops.push_back(posEven);
            reverse(a.begin(), a.begin() + posEven);   
        }
    }

    cout << ops.size() << '\n';
    write(ops);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}