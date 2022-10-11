#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

bool check(int sum) {
    bool ok = false;
    for (int i = 2; i < sum; i++)
        ok |= sum % i == 0;

    return ok;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int sum = accumulate(all(a), 0);
    vector<int> answer(n);
    iota(all(answer), 0);

    if (!check(sum))
        for (int i = 0; i < n; i++)
            if (check(sum - a[i])) {
                answer.erase(answer.begin() + i);
                break;
            }

    a = answer;
    cout << len(a) << '\n';
    for (int i = 0; i < len(a); i++)
        cout << a[i] + 1 << " \n"[i == len(a) - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}