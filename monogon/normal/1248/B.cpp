
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n / 2; i++) {
        sum1 += a[i];
    }
    for(int i = n / 2; i < n; i++) {
        sum2 += a[i];
    }
    cout << (sum1 * sum1) + (sum2 * sum2) << endl;
}