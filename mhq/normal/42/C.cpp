#include <bits/stdc++.h>
using namespace std;
int a[5];
/*
a, b, c, d;


*/
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int i = 1; i <= 4; i++) cin >> a[i];
    while (a[1] > 1) {
        if (a[1] % 2 != a[2] % 2) {
            cout << "+2" << '\n';
            a[2]++;
            a[3]++;
        }
        if (a[1] % 2 != 0) {
            cout << "+1" << '\n';
            a[1]++;
            a[2]++;
        }
        cout << "/1" << '\n';
        a[1] /= 2;
        a[2] /= 2;
    }
    while (a[2] > 1) {
        if (a[2] % 2 != a[3] % 2) {
            cout << "+3" << '\n';
            a[3]++;
            a[4]++;
        }
        if (a[2] % 2 != 0) {
            cout << "+2" << '\n';
            a[2]++;
            a[3]++;
        }
        cout << "/2" << '\n';
        a[2] /= 2;
        a[3] /= 2;
    }
    while (a[3] > 2) {
        if (a[3] % 2 == 0) {
            cout << "+3" << '\n';
            a[3]++;
            a[4]++;
        }
        cout << "+2" << '\n';
        a[3]++;
        cout << "/2" << '\n';
        a[3] /= 2;
    }
    if (a[3] == 2) {
        if (a[4] % 2 == 0) {
            cout << "/3" << '\n';
            a[3] = 1;
            a[4] /= 2;
        }
        else {
            cout << "+2" << '\n';
            cout << "+3" << '\n';
            a[4]++;
            cout << "/2" << '\n';
            cout << "/3" << '\n';
            a[3] = 1;
            a[4] /= 2;
        }
    }
    while (a[4] > 1) {
        if (a[4] % 2 == 1) {
            cout << "+3" << '\n';
            a[4]++;
            cout << "/3" << '\n';
            a[4] /= 2;
        }
        else {
            cout << "+2" << '\n';
            cout << "/3" << '\n';
            a[4] /= 2;
            cout << "+1" << '\n';
            cout << "+2" << '\n';
            cout << "/1" << '\n';
            cout << "/2" << '\n';
        }
    }
    return 0;
}