#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, l;
int a[nax];

void solve() {
    cin >> n >> l;
    double x = 0, y = l;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    int pa = 1, pb = n;

    double t = 0;
    int sa = 1, sb = 1;

    while (pa <= pb) {
        double dif_a = a[pa] - x;
        double dif_b = y - a[pb];
        double need_a = dif_a / sa;
        double need_b = dif_b / sb;

        if (need_a == need_b) {
            pa += 1;
            pb -= 1;
            t += need_a;
            x = a[pa - 1];
            y = a[pb + 1];
            sa += 1;
            sb += 1;
        } else if (need_a < need_b) {
            pa += 1;
            sa += 1;
            y -= need_a * sb;
            x = a[pa - 1];
            t += need_a;
        } else {
            pb -= 1;
            sb += 1;
            x += need_b * sa;
            y = a[pb + 1];
            t += need_b;
        }

    }

    t += (y - x) / (sa + sb);
    cout << t << '\n';
}

int main() {
    cout.precision(10);
    cout << fixed;
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/