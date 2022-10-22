#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int f(const vector<int>& p) {
    if ((int) p.size() > 7)
        return inf;
    int res = 0;
    for (int x : p) {
        res = res * 10 + x;
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, r;
    cin >> l >> r;

    for(int mask = 0; mask < (1 << 10); mask++) {
        vector<int> p;
        for (int i = 0; i < 10; i++) {
            if ((1 << i) & mask) {
                p.push_back(i);
            }
        }
        do {
            int x = f(p);
            if (l <= x && x <= r) {
                cout << x << "\n";
                return 0;
            }
        } while (next_permutation(p.begin(), p.end()));
    }

    cout << "-1\n";

    return 0;
}