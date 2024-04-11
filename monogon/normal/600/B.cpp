
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        cout << upper_bound(a, a + n, b[i]) - a << " ";
    }
    cout << endl;
}