#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int x, y, z, t1, t2, t3;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int t_lift = 0;
    if (z != x) t_lift += t2 * abs(z - x);
    if (abs(x - y) * t1 >= t_lift + 3 * t3 + t2 * abs(x - y)) {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}