#include <bits/stdc++.h>
using namespace std;
typedef complex < long double > base;
const long double pi = acos(-1.0);
long double len[105];
const long double eps = 1e-1;
int n;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 3 || n == 4) {
        cout << "No solution";
        return 0;
    }
    while (1) {
        base w(cos(2 * pi / n), sin(2 * pi / n));
        base st = 0;
        base ang = 1;
        for (int i = 0; i <= n - 3; i++) {
            len[i] = rand() % 1000;
            while (len[i] < eps) {
                len[i] = (rand() % 998) + 1;
            }
            st += ang * len[i];
            ang = ang * w;
        }
        base ang1 = ang;
        base ang2 = ang * w;
        long double ne1 = real(-st);
        long double ne2 = imag(-st);
        long double x1 = real(ang1);
        long double x2 = real(ang2);
        long double y1 = imag(ang1);
        long double y2 = imag(ang2);
        long double a = (ne1 * y2 - ne2 * x2) / (x1 * y2 - y1 * x2);
        long double b = (ne1 * y1 - ne2 * x1) / (x2 * y1 - x1 * y2);
        bool ok = true;
        if (a <= 1 || b <= 1 || a >= 1000 || b >= 1000) continue;
        len[n - 2] = a;
        len[n - 1] = b;
        for (int i = 0; i <= n - 1; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                if (abs(len[i] - len[j]) < 0.005) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok == false) continue;
        st = 0;
        ang = 1;
        for (int i = 0; i <= n - 1; i++) {
            cout << fixed << setprecision(5) << real(st) << " " << imag(st) << '\n';
            st += ang * len[i];
            ang = ang * w;
        }
        break;
    }
    return 0;
}