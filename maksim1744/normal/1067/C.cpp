/*
    24.10.2018 21:13:58
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int m = n;
    int i = 0;
    while (m > 0) {
        cout << i << ' ' << 0 << '\n';
        --m;
        if (i % 2 == 1 && m > 0) {
            cout << i << ' ' << 3 << '\n';
            --m;
        }
        ++i;
    }
    return 0;
}