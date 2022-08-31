/*
    19.10.2018 22:33:41
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int l = 0, r = 1000000000;
    int y1 = 99, y2 = 101, x1, x2;
    for (int i = 0; i < n; ++i) {
        if (l + 1 == r) {
            if (x1 > 0) {
                cout << x1 << ' ' << y2 << endl;
                string ans;
                cin >> ans;
                if (ans == "white") {
                    ++y2;
                } else {
                    --x1;
                    ++x2;
                }
            } else {
                cout << x2 << ' ' << y1 << endl;
                string ans;
                cin >> ans;
                if (ans == "white") {
                    --x1;
                    ++x2;
                } else {
                    --y1;
                }
            }
            continue;
        }
        int c = (l + r) / 2;
        cout << c << ' ' << 100 << endl;
        string ans;
        cin >> ans;
        if (ans == "white") {
            l = c;
        } else {
            r = c;
        }
        x1 = l; x2 = r;
    }
    cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << endl;
    return 0;
}