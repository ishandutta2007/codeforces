#include <bits/stdc++.h>
using namespace std;

int n, k, p, x, y;
int num, sum;

int main() {
    cin >> n >> k >> p >> x >> y;
    for (int i=0; i<k; i++) {
        int z; cin >> z;
        num += z>=y ? 1 : 0;
        sum += z;
    }
    if (n-k < (n+1)/2-num || sum+n-k > x) { cout << -1; return 0; }
    if (y == 1) { for (int i=0; i<n-k; i++) cout << 1 << ' '; return 0; }
    vector<int> v;
    int m = max(0, (n+1)/2-num);
    for (int i=0; i<(n-k) - m; i++) v.push_back(1), sum++;
    for (int i=0; i<m; i++) v.push_back(y), sum += y;
    if (sum > x) cout << -1;
    else {
        for (int i : v) cout << i << ' ';
    }
}