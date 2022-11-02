#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct zgz {
    double x;
    int y;
    void read() {
        cin >> x >> y;
        while (x >= 10) x /= 10, y++;
    }
    friend bool operator < (const zgz& a, const zgz& b) {
        return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y);
    }
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        zgz A, B;
        A.read();
        B.read();
        if (A < B) {
            cout << "<\n";
        }
        else if (B < A) {
            cout << ">\n";
        }
        else {
            cout << "=\n";
        }
    }
}