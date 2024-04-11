#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, h;
const int maxN = 1005;
int a[maxN];
int b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            b[j] = a[j];
        }
        sort(b + 1, b + i + 1);
        ll sum = 0;
        for (int j = i; j >= 1; j -= 2) {
            sum += b[j];
        }
        if (sum <= h) {
            cout << i;
            break;
        }
    }
    return 0;
}