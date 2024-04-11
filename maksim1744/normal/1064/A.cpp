/*
    19.10.2018 16:46:27
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    vector< int > v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    cout << max(0, v[2] + 1 - v[1] - v[0]) << '\n';
    return 0;
}