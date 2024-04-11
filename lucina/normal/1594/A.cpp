#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
using ll = int64_t;


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        ll n;
        cin >> n;
        cout << (-n + 1) << ' ' << n << '\n';
    }
}