#include <bits/stdc++.h>

using namespace std;



int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int ans = min(a, min(b - 1, c - 2));
    cout << ans * 3 + 3 << endl;
    return 0;
}