
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m, a, ma, mb;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        ma = max(ma, a);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a;
        mb = max(mb, a);
    }
    cout << ma << " " << mb << endl;
}