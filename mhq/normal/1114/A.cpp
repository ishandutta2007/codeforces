#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void bad() {
    cout << "NO";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 //   freopen("input.txt", "r", stdin);
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    a -= x;
    if (a < 0) {
        bad();
    }
    b += a;
    b -= y;
    if (b < 0) {
        bad();
    }
    c += b;
    c -= z;
    if (c < 0) {
        bad();
    }
    cout << "YES";
}