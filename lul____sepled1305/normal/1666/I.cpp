#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;

const int N = 205;
const ll INF = (ll)1e18;


int dig(int x, int y) {
    cout << "DIG " << x + 1 << " " << y + 1 << endl;
    fflush(stdout);
    int s;
    cin >> s;
    return s;
}

int get(int x, int y) {
    cout << "SCAN " << x + 1 << " " << y + 1 << endl;
    fflush(stdout);
    int s;
    cin >> s;
    return s;
}

int n, m;

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        int C = get(0, 0);
        int D = get(0, m - 1);
        int X = (D - 2 * (m - 1) + C) / 2;
        int Y = (C - D + 2 * (m - 1)) / 2;
        int Q = get(X / 2, 0);
        int x2 = (Q - Y + X) / 2, x1 = (X - x2);
        int P = get(0, Y / 2);
        int y2 = (P - X + Y) / 2, y1 = (Y - y2);
        if(dig(x2, y2)) {
            dig(x1, y1);
        } else {
            dig(x2, y1);
            dig(x1, y2);
        }
    }
}