#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int resp;
    cin >> resp;
    return resp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > p(n + 1, -1);
    int mx_pos = 1;
    for (int i = 2; i <= n; i++) {
        int c1 = ask(i, mx_pos);
        int c2 = ask(mx_pos, i);
        assert(c1 != c2);
        if (c1 > c2) {
            p[i] = c1;
        }
        else {
            p[mx_pos] = c2;
            mx_pos = i;
        }
    }
    p[mx_pos] = n;
    cout << "! ";
    for (int c = 1; c <= n; c++) cout << p[c] << " ";
    cout << endl;
    return 0;
}