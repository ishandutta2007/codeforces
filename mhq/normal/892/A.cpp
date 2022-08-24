#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 5;
int n;
long long a[maxN];
long long b[maxN];
long long max1, max2;
int main() {
    //freopen("input.txt", "r", stdin);
    //cout << mult(100000, 100000);
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n <= 2) {
        cout << "YES";
        return 0;
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] > max1) {
            max2 = max1;
            max1 = b[i];
        }
        else if (b[i] > max2) {
            max2 = b[i];
        }
    }
    //cout << sum << "  " << max1 << " " << max2 << " ";
    //cout << max1 + max2;
    if (sum <= max1 + max2) {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}