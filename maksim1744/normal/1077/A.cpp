/*
    17.11.2018 0:41:36
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        long long a, b, k;
        cin >> a >> b >> k;
        cout << (k / 2) * (a - b) + (k % 2) * a << '\n';
    }
    return 0;
}