/*
    25.03.2019 22:28:11
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    int rem = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        rem = (rem + a[i]) % 2;
    }
    sort(a.rbegin(), a.rend());
    // show(a);
    vector<long long> delta(n);
    vector<long long> delta1(n);
    long long sm = 0;
    long long ssm = 0;
    long long i1 = n - 1;
    for (long long i = 0; i < n; ++i) {
        sm += a[i];
        while (i1 < i) {
            ++i1;
            ssm -= a[i1];
        }
        while (i1 > i && a[i1] < (i + 1)) {
            ssm += a[i1];
            --i1;
        }
        delta[i] = ssm + i * (i + 1) + (i1 - i) * (i + 1) - sm;
        // showt(i, i1, sm, ssm, delta[i]);
        delta1[i] = delta[i] + min(i + 1, a[i]) + a[i];
    }
    // show(delta, delta1);
    long long mn = 0, mx = n;
    bool can = true;
    vector<pair<long long, long long>> forbidden;
    for (int i = 0; i < n; ++i) {
        pair<long long, long long> pr;
        // pr = {delta1[i] + 1, a[i] - 1};
        pr = {max(a[i], delta1[i] + 1), n};
        pr.first = max(0ll, pr.first);
        pr.second = min(n, pr.second);
        // if (pr.first <= 21 && pr.second >= 21)
        //     showt(i, delta[i], delta1[i], a[i], pr);
        if (pr.first <= pr.second) {
            forbidden.push_back(pr);
        }
        if (delta[i] + (i + 1) < 0) {
            can = false;
            break;
        }
        pr = {0ll, -delta[i] - 1};
        pr.second = min(n, pr.second);
        // if (pr.first <= 21 && pr.second >= 21)
        //     showt(i, delta[i], delta1[i], a[i], pr);
        if (pr.first <= pr.second) {
            forbidden.push_back(pr);
        }
    }
    if (!can) {
        cout << -1 << '\n';
        return 0;
    }
    sort(forbidden.begin(), forbidden.end());
    forbidden.erase(unique(forbidden.begin(), forbidden.end()), forbidden.end());
    // show(forbidden);
    vector<int> ans;
    int r = -1;
    for (auto p : forbidden) {
        if (p.second <= r) continue;
        for (int j = r + 1; j < p.first; ++j) {
            if (j % 2 == rem)
                ans.push_back(j);
        }
        r = p.second;
    }
    for (int j = r + 1; j <= n; ++j) {
        if (j % 2 == rem)
            ans.push_back(j);
    }
    if (ans.empty())
        ans.push_back(-1);
    for (auto k : ans) {
        cout << k << ' ';
    }
    cout << '\n';
    return 0;
}