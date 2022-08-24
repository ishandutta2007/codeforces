#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
void bad() {
    cout << "NO";
    exit(0);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        string dir;
        cin >> t >> dir;
        if (cur == 0) {
            if (dir != "South") {
                bad();
            }
        }
        if (cur == 20000) {
            if (dir != "North") {
                bad();
            }
        }
        if (dir == "South") {
            if (cur + t > 20000) bad();
            cur += t;
        }
        if (dir == "North") {
            if (cur - t < 0) bad();
            cur -= t;
        }
    }
    if (cur) bad();
    else cout << "YES";
    return 0;
}