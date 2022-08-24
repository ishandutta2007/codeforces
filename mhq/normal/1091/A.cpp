#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    srand(239);
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int y, b, r;
    cin >> y >> b >> r;
    int take = min(y, min(b - 1, r - 2));
    cout << 3 * take + 3;
    return 0;
}