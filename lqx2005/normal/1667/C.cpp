#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
void solve() {
    int n;
    cin >> n;
    int m = n / 3 * 2;
    if(n % 3 == 0) {
        cout << m << endl;
        cout << 1 << " " << 1 << endl;
        for(int i = 2; i <= m / 2; i++) cout << i <<" " << m / 2 + 2 - i << endl;
        for(int i = m / 2 + 1; i <= m; i++) cout << i <<" " << m / 2 + 1 + m - i << endl;
    } else {
        cout << m + 1 << endl;
        for(int i = 1; i <= m / 2; i++) cout << i <<" " << m / 2 + 1 - i << endl;
        for(int i = m / 2 + 1; i <= m + 1; i++) cout << i <<" " << m / 2 + 1 + m + 1 - i << endl;
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(t = 1; t--; ) solve();
    return 0;
}