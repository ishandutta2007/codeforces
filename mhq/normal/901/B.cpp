#include <bits/stdc++.h>

using namespace std;
int n;
struct polinom {
    long double dg[200];
    int sz;
};
const int t[2] = {-1, 1};
polinom generate_(int n) {
    polinom a;
    a.sz = n;
    a.dg[n] = 1;
    for (int i = n - 1; i >= 0; i--) a.dg[i] = t[rand() % 2];
    return a;
}
void print(polinom a) {
    cout << a.sz << "\n";
    for (int i = 0; i <= a.sz; i++) cout << a.dg[i] << " ";
    cout << "\n";
}
const long double eps = 1e-7;
polinom mod(polinom a, polinom b) {
    polinom c; c.sz = a.sz;
    for (int i = 0; i <= c.sz; i++) c.dg[i] = a.dg[i];
    if (b.sz == 0) {
        c.sz = 0;
        c.dg[0] = 0;
        return c;
    }
    for (;;) {
        if (c.sz < b.sz) break;
        double cf = 1.0 * c.dg[c.sz] / b.dg[b.sz];
        for (int i = 0; i <= b.sz; i++) c.dg[c.sz - i] -= b.dg[b.sz - i] * cf;
        int fnd = 0;
        for (int i = c.sz; i >= 0; i--)
            if (abs(c.dg[i]) > eps || i == 0) {
                c.sz = i;
                break;
            }

    }
    return c;
}
int go(polinom a, polinom b) {
    if (b.sz == 0 && b.dg[0] == 0) return 0;
    if (abs(a.sz - b.sz) > 1) return -2;
    return go(b, mod(a, b)) + 1;
}
int main() {
   srand(time(NULL));
    cin >> n;
    while (1) {
      //  cerr << "iter\n";
        polinom a = generate_(n);
        polinom b = generate_(n - 1);
        int h = go(a, b);
        if (h == n) {
            print(a);
            print(b);
            return 0;
        }
    }
    return 0;
}