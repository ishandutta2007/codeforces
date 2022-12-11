#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = int64_t(2e18) + 5;

void run_case() {
    int N;
    cin >> N;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> alternating_sum(N, 0);
    alternating_sum[0] = A[0];

    for (int i = 1; i < N; i++)
        alternating_sum[i] = A[i] - alternating_sum[i - 1];

    array<int64_t, 2> parity_sum = {0, 0};

    for (int i = 0; i < N; i++)
        parity_sum[i % 2] += A[i];

    if (parity_sum[0] == parity_sum[1] && *min_element(alternating_sum.begin(), alternating_sum.end()) >= 0) {
        cout << "YES" << '\n';
        return;
    }

    vector<int64_t> prefix_min(N + 1, INF64);

    for (int i = 0; i < N; i++)
        prefix_min[i + 1] = min(prefix_min[i], alternating_sum[i]);

    vector<int64_t> parity_suffix_min(N + 2, INF64);

    for (int i = N - 1; i >= 0; i--)
        parity_suffix_min[i] = min(alternating_sum[i], parity_suffix_min[i + 2]);

    for (int i = 0; i < N - 1; i++) {
        int64_t diff = A[i + 1] - A[i];
        array<int64_t, 2> nparity_sum = parity_sum;
        nparity_sum[i % 2] += diff;
        nparity_sum[(i + 1) % 2] -= diff;

        if (nparity_sum[0] == nparity_sum[1] && prefix_min[i] >= 0 && alternating_sum[i] + diff >= 0) {
            if (parity_suffix_min[i + 1] - 2 * diff >= 0 && parity_suffix_min[i + 2] + 2 * diff >= 0) {
                  // cout<<i<<'\n';
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}