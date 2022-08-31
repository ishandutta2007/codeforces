/*
    18.10.2018 19:36:25
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int c1 = abs(x - y) * t1;
    int c2 = abs(x - z) * t2 + 3 * t3 + abs(x - y) * t2;
    if (c2 <= c1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}