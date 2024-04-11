#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const long long inf = 1e9;


void solve () {
    long long a, b, c;

    cin >> a >> b >> c;
    long long first = 1, second = (inf / b * b);

    if (a * first < ((first - 1) / b + 1) * c) {
        cout << first;
    } else cout << -1;
    cout << ' ';

    if (a * second > ((second - 1) / b + 1) * c) {
        cout << second;
    } else cout << -1;
    cout << '\n';
}

int main () {
    int T;

    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    Sue is best girl in A19.
*/