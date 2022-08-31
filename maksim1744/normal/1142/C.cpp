/*
    01.04.2019 00:35:53
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

const int max_x = 1e6 + 5;
const long double inf = 1e13;
const long double e = 1e-7;

long double intersect(const pair<long long, long long>& a, pair<long long, long long>& b) {
    return (long double)(b.second - a.second) / (long double)(a.first - b.first);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<long long, long long>> pt0(n);
    for (int i = 0; i < n; ++i) {
        cin >> pt0[i].first >> pt0[i].second;
        // pt0[i].first += max_x;
    }
    sort(pt0.begin(), pt0.end());
    vector<pair<long long, long long>> pt;
    for (int i = 1; i <= pt0.size(); ++i) {
        if (i == pt0.size() || pt0[i].first != pt0[i - 1].first)
            pt.push_back(pt0[i - 1]);
    }
    n = pt.size();
    // show(pt);
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<pair<long long, long long>> lines(n);
    for (int i = 0; i < n; ++i) {
        lines[i] = {pt[i].first * 2, pt[i].second - pt[i].first * pt[i].first};
    }
    show(lines);
    vector<pair<long double, int>> hull;
    hull.push_back({-inf, 0});
    for (int i = 1; i < n; ++i) {
        long double start = intersect(lines[hull.back().second], lines[i]);
        while (!hull.empty() && start <= hull.back().first + e) {
            hull.pop_back();
            start = intersect(lines[hull.back().second], lines[i]);
        }
        hull.emplace_back(start, i);
    }
    int ans = 0;
    int now_ind = 0;
    long double last_x = -1e7;
    show(hull);
    vector<long double> answers;
    while (now_ind < n - 1) {
        shows;
        long double L = last_x, R = 1e7;
        // show(L, R);
        int Ind = -1;
        for (int i = 0; i < 50; ++i) {
            long double xb = (L + R) / 2.0;
            int l = 0, r = hull.size();
            while (r - l > 1) {
                int c = (l + r) / 2;
                if (hull[c].first <= xb + e) {
                    l = c;
                } else {
                    r = c;
                }
            }
            int ind = hull[l].second;
            // show(xb, ind);
            long double dx = xb - pt[now_ind].first;
            long double yb = -xb * xb + (long double)lines[ind].first * xb + (long double)lines[ind].second;
            // show(xb, yb, ind, yb+dx*dx, pt[now_ind].second);
            if (abs(yb + dx * dx - (long double)pt[now_ind].second) < e) {
                L = xb;
                Ind = ind;
            } else {
                R = xb;
            }
        }
        // show(L, R);
        // if (Ind != -1)
            last_x = L;
        // long double yb = ...;
        ++now_ind;
        // ++ans;
        answers.push_back(L);
    }
    sort(answers.begin(), answers.end());
    show(answers);
    for (int i = 0; i < answers.size(); ++i) {
        if (i == 0 || answers[i] >= answers[i - 1] + e * 3)
            ++ans;
    }
    cout << ans << '\n';
    return 0;
}