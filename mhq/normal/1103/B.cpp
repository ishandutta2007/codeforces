#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    char ans;
    cin >> ans;
    if (ans == 'x') return true;
    else return false;
}
void solve() {
    int num = 1;
    while (true) {
        if (ask(num, 2 * num)) {
            break;
        }
        num *= 2;
    }
    if (num == 1) {
        if (ask(2, 1)) {
            cout << "! " << 1 << endl;
            return ;
        }
        else {
            cout << "! " << 2 << endl;
            return ;
        }
    }
    int r = 2 * num;
    int l = num;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(num, mid)) {
           r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << "! " << r << endl;
    return ;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    while (true) {
        string s;
        cin >> s;
        if (s == "end") exit(0);
        assert(s == "start");
        solve();
    }
    return 0;
}