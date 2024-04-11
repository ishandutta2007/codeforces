
#include <bits/stdc++.h>

using namespace std;

// The formula may cause overflow, but we don't actually
// have to compute it to find the b_i values.
// We must take b[i] up to x, where
// a_i - 3x^2 + 3x - 1 >= A
// for some constant A.
// A must be in the range [-10^18, 10^18]

// binary search on x in range [0, a_i]

const int N = 1e5 + 5;
int n;
long long k, a[N], b[N];

long long check(long long A) {
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        long long L = 0, R = a[i];
        while(L < R) {
            long long m = L + (R - L + 1) / 2;
            if(a[i] - 3 * m * m + 3 * m - 1 >= A) {
                L = m;
            }else {
                R = m - 1;
            }
        }
        b[i] = L;
        sum += L;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long r = 4'000'000'000'000'000'000LL, l = -r;
    long long k2 = 0;
    assert(check(l) >= k);
    assert(check(r) == 0);
    while(l < r) {
        long long m = l + (r - l + 1) / 2;
        k2 = check(m);
        if(k2 < k) {
            r = m - 1;
        }else {
            l = m;
        }
    }
    k2 = check(l);
    assert(k2 >= k);
    for(int i = 0; i < n; i++) {
        if(k2 > k && b[i] > 0 && a[i] - 3 * b[i] * b[i] + 3 * b[i] - 1 == l) {
            b[i]--;
            k2--;
        }
    }
    assert(k2 == k);
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}