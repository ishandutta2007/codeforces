#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T; T -- ;) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (max(l1, l2) <= min(r1, r2))
            cout << max(l1, l2) << '\n';
        else cout << l1 + l2 << '\n';
    }
}