#include <bits/stdc++.h>
using namespace std;
int l, r, u, d;
int n;
char x;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == 'L') l++;
        if (x == 'R') r++;
        if (x == 'U') u++;
        if (x == 'D') d++;
    }
    cout << 2* min(l, r) + 2*min(u, d);
    return 0;
}