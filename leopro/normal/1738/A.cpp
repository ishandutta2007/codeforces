#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    vector<int> u0, u1;
    for (int i = 0; i < n; ++i) (a[i] ? u1 : u0).push_back(b[i]);
    sort(u0.rbegin(), u0.rend());
    sort(u1.rbegin(), u1.rend());
    int cnt1 = accumulate(a.begin(), a.end(), 0);
    int cnt0 = n - cnt1;
    ll ans = accumulate(b.begin(), b.end(), 0LL);
    ll res = 0;
    {
        ll cur = ans;
        int mx1 = cnt0, mx0 = cnt1;
        for (int i = 0; i < mx0 && i + 1 < u0.size(); ++i) cur += u0[i];
        for (int i = 0; i < mx1 && i < u1.size(); ++i) cur += u1[i];
        res = max(res, cur);
    }
    {
        ll cur = ans;
        int mx1 = cnt0, mx0 = cnt1;
        for (int i = 0; i < mx0 && i < u0.size(); ++i) cur += u0[i];
        for (int i = 0; i < mx1 && i + 1 < u1.size(); ++i) cur += u1[i];
        res = max(res, cur);
    }
    answer(res);
}