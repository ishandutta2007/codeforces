#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    ll x;
    string s;
    cin >> n >> x >> s;
    x -= (1ll << (s.back() - 'a'));
    x += (1ll << (s.end()[-2] - 'a'));
    x = abs(x);

    priority_queue<int> q;
    for (int i = 0; i < n - 2; i++)
        q.push(s[i] - 'a' + 1), x += (1 << (s[i] - 'a'));
    while (!q.empty()) {
        int b = (1 << q.top());
        q.pop();
        if (b <= x)
            x -= b;
    }
    cout << (!x ? "YES" : "NO") << '\n';
}