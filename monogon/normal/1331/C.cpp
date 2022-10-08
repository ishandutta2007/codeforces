
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int perm[6] = {4, 1, 3, 2, 0, 5};
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < 6; i++) {
        if((n >> i) & 1) ans += (1 << perm[i]);
    }
    cout << ans << endl;
}