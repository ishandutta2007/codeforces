#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 30;

vector<int> bits(int x) {
    vector<int> res;
    for (int j = LOG - 1; j >= 0; j--) {
        if ((1 << j) & x)
            res.push_back(j);
    }
    return res;
}

void work() {
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        vector<int> bu = bits(u), bv = bits(v);
        if (u > v || (int) bu.size() < (int) bv.size()) {
            cout << "NO\n";
        } else {
            int ok = 1;
            reverse(bu.begin(), bu.end());
            reverse(bv.begin(), bv.end());
            while (!bv.empty() && bu.back() == bv.back()) {
                bu.pop_back();
                bv.pop_back();
            }
            if (!bv.empty()) {
                bv.pop_back();
                while ((int) bu.size() > (int) bv.size())
                    bu.pop_back();
                reverse(bu.begin(), bu.end());
                reverse(bv.begin(), bv.end());
                for (int i = 0; i < (int) bv.size(); i++) {
                    if (bv[i] < bu[i]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}