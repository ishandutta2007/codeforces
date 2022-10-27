#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    int T;

    for (cin >> T ; T -- ;) {
        int x, y, n;
        cin >> x >> y >> n;
        /**
        xa + y <= n
        */

        int w = (n - y) / x;
        printf("%d\n", x * w + y);
    }
}