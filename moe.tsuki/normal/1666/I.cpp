#include <bits/stdc++.h>
using namespace std;

pair<int,int> ans[2];
int ask(int x, int y) {
    int sum;
    cout << "SCAN " << x << ' ' << y << '\n';
#ifdef CKISEKI
    return abs(x - ans[0].first) + abs(x - ans[1].first) + abs(y - ans[0].second) + abs(y - ans[1].second);
#endif
    cin >> sum;
    return sum;
}

int dig(int x, int y) {
    int res;
    cout << "DIG " << x << ' ' << y << '\n';
#ifdef CKISEKI
    return ans[0] == pair{x, y} || ans[1] == pair{x, y};
#endif
    cin >> res;
    return res;
}
int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
#ifdef CKISEKI
        cin >> ans[0].first >> ans[0].second;
        cin >> ans[1].first >> ans[1].second;
#endif
        int A = ask(1, 1); // = Xsum - 2 + Ysum - 2
        int B = ask(n, 1); // = 2n - Xsum + Ysum - 2
        int Ysum = (A + B - 2 * n + 6) / 2;
        int Xsum = (A - B + 2 * n + 2) / 2;

        int C = ask(Xsum / 2, 1); // = Xdiff + Ysum - 2
        int Xdiff = C - Ysum + 2;
        int D = ask(1, Ysum / 2); // = Ydiff + Xsum - 2
        int Ydiff = D - Xsum + 2;

        int x1 = (Xsum + Xdiff) / 2;
        int x2 = (Xsum - Xdiff) / 2;
        int y1 = (Ysum + Ydiff) / 2;
        int y2 = (Ysum - Ydiff) / 2;
        // cerr << "Xsum = " << Xsum << '\n';
        // cerr << "Ysum = " << Ysum << '\n';
        // cerr << "Xdiff = " << Xdiff << '\n';
        // cerr << "Ydiff = " << Ydiff << '\n';

        if (dig(x1, y1)) {
            dig(x2, y2);
        } else {
            dig(x1, y2);
            dig(x2, y1);
        }
    }
}