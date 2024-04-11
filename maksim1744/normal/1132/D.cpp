/*
    26.03.2019 21:07:34
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

const long long mx = 1e9l * 1e9l * 4l;

// struct comp {
    // bool operator()(pair<long long, long long> a, pair<long long, long long> b) const {
    //     return a.first / a.second < b.first / b.second;
    // }
// };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        s.push({a[i] / b[i], i});
    }
    long long l = -1, r = mx;
    while (r - l > 1) {
        long long m = l + (r - l) / 2;
        bool ok = true;
        int ind = 0;
        auto aa = a;
        auto ss = s;
        while (!ss.empty()) {
            if (ss.top().first < ind) {
                ok = false;
                break;
            }
            if (ss.top().first >= k - 1) {
                ok = true;
                break;
            }
            auto p = ss.top();
            ss.pop();
            aa[p.second] += m;
            p.first = aa[p.second] / b[p.second];
            if (p.first <= k - 1)
                ss.push(p);
            ++ind;
        }
        if (ok) r = m;
        else l = m;
    }
    if (r == mx) r = -1;
    cout << r << '\n';
    return 0;
}