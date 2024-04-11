
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// only ever need to increase the upper half of numbers
// to increase the median to M, we need to ensure all
// of the top ceil(n/2) numbers are at least M.

const int MAX_N = 2e5 + 5;
int n;
ll k;
ll a[MAX_N], prefix[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    prefix[n / 2] = a[n / 2];
    for(int i = 1 + n / 2; i < n; i++) {
        prefix[i] = a[i] + prefix[i - 1];
    }
    ll median = a[n / 2];
    for(int i = n / 2; i < n; i++) {
        int num = i - n / 2 + 1;
        ll minop = num * a[i] - prefix[i];
        if(minop <= k) {
            median = a[i] + (k - minop) / num;
        }
    }
    cout << median << endl;
}