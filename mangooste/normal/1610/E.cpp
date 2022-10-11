#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int answer = 2;
    for (int i = 0; i < n - 1; i++) {
        int take = 2, last = n - 1;
        while (true) {
            int pos = lower_bound(all(a), (a[i] + a[last]) / 2 + 1) - a.begin() - 1;
            pos = min(pos, last - 1);
            if (pos <= i)
                break;

            if (a[i] == a[pos]) {
                take += pos - i;
                break;
            }

            take++;
            last = pos;
        }
        answer = max(answer, take);
    }

    cout << n - answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}