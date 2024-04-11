#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int myx = (1 << 29) + 1;
int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
#ifdef DEBUG
    return __gcd(myx + a, myx + b);
#endif
    int gc;
    cin >> gc;
    return gc;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int cur_x = 0;
        for (int i = 1; i <= 29; i++) {
            int c = (1 << i);
            int need_a = (c - cur_x) % c;
            need_a = (need_a + c) % c;
            if (need_a == 0) {
                need_a += c;
            }
            int need_b = (need_a + c);
            int f = ask(need_a, need_b);
            if (f % c != 0) {
                cur_x += c / 2;
            }
        }
        int c = (1 << 30);
        int f_x = cur_x;
        int f_y = (cur_x + c / 2);
        int A = -1;
        int B = -1;
        for (int a = 1; a <= 100; a++) {
            if (A != -1) break;
            for (int b = 1; b <= 100; b++) {
                if (a == b) continue;
                if (__gcd(f_x + a, f_x + b) != __gcd(f_y + a, f_y + b)) {
                   A = a;
                   B = b;
                   break;
                }
            }
        }
        assert(A != -1 && B != -1);
        int f = ask(A, B);
        if (f != __gcd(f_x + A, f_x + B)) {
            cur_x += (c / 2);
        }
        cout << "! " << cur_x << endl;
    }
    return 0;
}