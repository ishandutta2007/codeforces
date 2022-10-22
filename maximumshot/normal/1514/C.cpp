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

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int res = 1;
    vector<int> seq;
    for (int p = 1; p < n; p++) {
        if (gcd(n, p) == 1) {
            res = (1ll * res * p) % n;
            seq.push_back(p);
        }
    }

    if (res != 1)
        seq.pop_back();

    cout << (int) seq.size() << "\n";
    for (auto x : seq)
        cout << x << " ";
    cout << "\n";

    return 0;
}