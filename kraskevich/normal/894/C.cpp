#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> as(n);
    for (int& a : as)
        cin >> a;
    for (int a : as)
        if (a % as[0]) {
            cout << -1 << endl;
            return 0;
        }
    cout << 2 * n << endl;
    for (int a : as)
        cout << a << " " << as[0] << " ";
    cout << endl;
}