/*
    05.11.2018 18:22:49
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int s12, s23, s13;
    s12 = ask(1, 2);
    s23 = ask(2, 3);
    s13 = ask(1, 3);
    int s = (s12 + s23 + s13) / 2;
    vector< int > a(n);
    a[0] = s - s23;
    a[1] = s - s13;
    a[2] = s - s12;
    for (int i = 0; i < n - 3; ++i) {
        a[i + 3] = ask(1, i + 4) - a[0];
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}