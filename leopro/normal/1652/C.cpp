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
    multiset<ll> p;
    for (int x : a) p.insert(x);
    ll total = accumulate(a.begin(), a.end(), 0LL);
    vector<ll> cur{total};
    while (!cur.empty()) {
        if (cur.size() > n) answerReturn("NO")
        ll x = cur.back();
        cur.pop_back();
        if (p.find(x) != p.end()) {
            p.erase(p.find(x));
            continue;
        }
        if (x == 1) answerReturn("NO")
        ll u = x / 2, v = (x + 1) / 2;
        cur.push_back(u);
        cur.push_back(v);
    }
    answerReturn("YES")
}