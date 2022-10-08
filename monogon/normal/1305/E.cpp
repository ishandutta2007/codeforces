
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5005;
int n, m;
ll a[N];

int solve(int n, int m) {
    if(m > (n / 2) * ((n - 1) / 2)) {
        return -1;
    }
    int k = 1;
    for(; k <= n; k++) {
        if(m < (k / 2) * ((k - 1) / 2)) break;
    }
    k--;
    for(int i = 1; i <= k; i++) {
        a[i - 1] = i;
    }
    int dif = ((k + 1) / 2) * (k / 2) - m;
    a[k] = (k + 1 + 2 * dif);
    for(int i = k + 2; i <= n; i++) {
        a[i - 1] = 5e8 + 10 * n * i;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if(solve(n, m) == -1) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}