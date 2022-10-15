#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

template<typename T>
void setMax(T &t, T other) { t = max(t, other); }

template<typename T>
void setMin(T &t, T other) { t = min(t, other); }

#define answerExit(ans) { cout << (ans) << '\n'; exit(0); }
#define answerReturn(ans) { cout << (ans) << '\n'; return; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.rbegin(), a.rend());
    cout << a[0] + a[1] << '\n';
}