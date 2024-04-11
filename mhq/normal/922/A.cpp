#include <bits/stdc++.h>
using namespace std;
int x, y;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    swap(x, y);
    if (x == 0) {
        cout << "No";
        return 0;
    }
    if ((x + y) % 2 == 0) {
        cout << "No";
        return 0;
    }
    if (y < (x - 1)) {
        cout << "No";
        return 0;
    }
    if (x == 1 && y > 0) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}