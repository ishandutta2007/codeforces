#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
int n;
bool ask(int r1, int c1, int r2, int c2) {
    if (min(min(r1, r2), min(c1, c2)) < 1 || max(max(r1, r2), max(c1, c2)) > n) return false;
    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    string s;
    cin >> s;
    return (s == "YES");
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int x = n;
    int y = n;
    deque < int > ans;
    // R - 1
    // D - 2
    while (x + y > n + 1) {
        if (ask(1, 1, x - 1, y)) {
            ans.push_front(2);
            x--;
        }
        else {
            ans.push_front(1);
            y--;
        }
    }
    x = 1;
    y = 1;
    while (x + y < n + 1) {
        if (ask(x, y + 1, n, n)) {
            ans.push_front(1);
            y++;
        }
        else {
            ans.push_front(2);
            x++;
        }
    }
    cout << "! ";
    for (int i = n - 2; i >= 0; i--) {
        if (ans[i] == 1) cout << "R";
        else cout << "D";
    }
    for (int i = n - 1; i <= 2 * n - 3; i++) {
        if (ans[i] == 1) cout << "R";
        else cout << "D";
    }
    cout << endl;
    return 0;
}