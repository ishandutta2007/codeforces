#include <bits/stdc++.h>
using namespace std;
int n, m;
int a, b;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    long double mn = 1e7;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        mn = min(mn, ((long double)m * a) / b);
    }
    cout << fixed << setprecision(15) << mn;
    return 0;
}