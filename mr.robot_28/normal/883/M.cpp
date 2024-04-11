#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << max(2, (abs(x2 - x1) + 1)) * 2 + max(2, (abs(y2 - y1) + 1)) * 2 << '\n';
    return 0;
}