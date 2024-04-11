#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    int s = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        s += a[i] - 1;
    }
    s %= 2;
    if (s % 2) {
        cout << "errorgorn\n";
    } else cout << "maomao90" << '\n';
}

int main() {
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    long time no rated round
*/