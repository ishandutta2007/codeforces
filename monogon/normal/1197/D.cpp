
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// keep a prefix sum array of a.
// then you can find the cost of a given subarray
// since you have the range sum and the length.

// if m = 1, equivalent to finding maximum sum subarray when you subtract
// k from each entry.
// if m = 2: 1 => 1, 2 => 1, 3 => 2, 4 => 2, 5 => 3, ...
// subtract k from every mth entry.
// loop through all m possible starting positions.

const int MAX_N = 3e5 + 5;

int n, m;
ll k;
ll a[MAX_N];
ll dif[MAX_N];

ll findBest(int off) {
    ll best = 0;
    int j = off;
    int j2 = off;
    while(j2 < n) {
        int besti = 0;
        ll bestsum = 0;
        for(int i = 0; i < m && j2 + i + 1 <= n; i++) {
            ll sumArray = dif[j2 + i + 1] - dif[j] - k * ((j2 + i - j + 1 + m - 1) / m);
            if(sumArray > bestsum) {
                bestsum = sumArray;
                besti = i;
            }
        }
        best = max(best, bestsum);
        j2 += m;
        if(j2 >= n) break;
        while(j < j2 && dif[j2] - dif[j] - k * ((j2 - j) / m) <= 0) {
            j += m;
        }
    }
    return best;
}

int main() {
    cin >> n >> m >> k;
    dif[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dif[i + 1] = dif[i] + a[i];
    }
    ll M = 0;
    for(int i = 0; i < m; i++) {
        ll best = findBest(i);
        M = max(M, best);
    }
    cout << M << endl;
}