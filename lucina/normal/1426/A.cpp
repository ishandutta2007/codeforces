#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        int x, y;
        cin >> x >> y;

        int cur = 3;

        int bar = 1;
        while (true) {
            if (cur > x) {
                cout << bar << '\n';
                break;
            }
            cur += y;
            bar += 1;
        }
    }
}