#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    char x[10];
    cin >> x >> x + 2;
    set <char> setik;
    for (int i = 0 ; i < 4 ;++ i) {
        setik.insert(x[i]);
    }
    cout << setik.size() - 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;


    for (cin >> T ; T -- ;) {
        solve();
    }
}