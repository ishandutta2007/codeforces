#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

constexpr int N = 1000, PERIOD = 34;
int grundy[N];

void solve(int test_num) {
    int n;
    string s;
    cin >> n >> s;

    int alice = count(all(s), 'R');
    int bob = count(all(s), 'B');
    if (alice > bob) {
        cout << "Alice\n";
        return;
    }
    if (bob > alice) {
        cout << "Bob\n";
        return;
    }

    int tot = 0;
    for (int i = 0, j = 0; i < n - 1; i = j) {
        j++;
        while (j < n && s[j] != s[j - 1]) j++;
        int val = j - i - 1;
        while (val > N) val -= PERIOD;
        tot ^= grundy[val];
    }
    cout << (tot ? "Alice" : "Bob") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    grundy[0] = 0;
    grundy[1] = 1;
    for (int n = 2; n < N; n++) {
        vector<bool> used(n + 1);
        for (int first = 0; first < n; first++) {
            int x = grundy[max(0, first - 1)] ^ grundy[max(0, n - first - 2)];
            if (x <= n) used[x] = true;
        }
        grundy[n] = 0;
        while (used[grundy[n]]) grundy[n]++;
    }

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}