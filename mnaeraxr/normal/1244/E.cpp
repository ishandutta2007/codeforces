#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include <algorithm>
#include <numeric>

#define endl '\n'

using namespace std;

long long solve(vector<long long> a, long long n, long long k) {
    sort(a.begin(), a.end());

    vector<long long> A(n + 1);

    for (int i = 0; i < n; ++i) {
        A[i + 1] = A[i] + a[i];
    }

    long long lo = -1, hi = a.back() - a[0];

    while (lo + 1 < hi) {
        long long m = (lo + hi) / 2;

        bool ok = false;

        for (long long i = 0, j = 0; i < n && !ok; ++i) {
            while (j < n && a[j] - a[i] <= m)
                ++j;

            long long left = a[i] * i - A[i];
            long long right = A[n] - A[j] - (a[i] + m) * (n - j);

            if (left + right <= k) {
                ok = true;
            }
        }

        if (ok)
            hi = m;
        else
            lo = m;
    }

    return hi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;

    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long A = solve(a, n, k);

    for (auto &x : a) x *= -1;

    long long B = solve(a, n, k);

    cout << min(A, B) << endl;

    return 0;
}