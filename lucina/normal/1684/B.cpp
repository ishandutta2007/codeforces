#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    for (cin >> T ; T -- ;) {
        int64_t a, b, c;
        cin >> a >> b >> c;
        int64_t x = a + int(1e9) * b;
        cout << x << ' ' << b << ' ' << x + c << '\n';
    }
}