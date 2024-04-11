#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
  // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst--) {
        int x;
        cin >> x;
        int z = sqrt(x) + 2;
        while ((z - 1) * (z - 1) >= x) z--;
        cout << z << '\n';
    }
}