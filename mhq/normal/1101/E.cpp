#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
set < int > mn, mx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char s;
        cin >> s;
        if (s == '+') {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            mn.insert(x);
            mx.insert(y);
        }
        else {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            bool ok1 = (*(--mn.end())) <= a;
            bool ok2 = (*(--mx.end())) <= b;
            if (ok1 && ok2) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}