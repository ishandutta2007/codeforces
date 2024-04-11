#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int ans[150];

void print(int x, int y) {
    for (int i = 1; i <= x; i++) {
        cout << "(" << i << ",1)" << " ";
    }
    for (int i = 2; i <= y; i++) {
        cout << "(" << x << "," << i << ")" << " ";
    }
    cout << '\n';
}
int main() {
    int x1, y1, x2, y2, n, m;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if (abs(x1 - x2) < abs(y1 - y2)) {
        swap(x1, y1);
        swap(x2, y2);
        swap(n, m);
    }
    //cout << y1 << " " << y2 << '\n';
    if (abs(x1 - x2) > 4) {
        cout << "Second";
        return 0;
    }
    if (abs(y1 - y2) == 4) {
        cout << "Second";
        return 0;
    }
    if (abs(y1 - y2) == 3 && abs(x1 - x2) == 4) {
        cout << "Second";
        return 0;
    }
    cout << "First";
    return 0;
}