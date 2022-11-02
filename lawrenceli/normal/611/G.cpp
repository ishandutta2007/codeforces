#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 1000100;
const int mod = 1e9 + 7;

int n, x[maxn], y[maxn], mx[maxn], my[maxn], px[maxn], py[maxn];

ll area(int i, int j, int k) {
    return ll(x[i]) * y[j] + ll(x[j]) * y[k] + ll(x[k]) * y[i] - ll(y[i]) * x[j] - ll(y[j]) * x[k] - ll(y[k]) * x[i];
}

int add(int a, int b) { return a + b - (a + b >= mod) * mod; }
int sub(int a, int b) { return a - b + (a - b < 0) * mod; }
int mult(int a, int b) { return ll(a) * b % mod; }
int fix(ll a) { return sub(a % mod, 0); }

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    reverse(x, x + n);
    reverse(y, y + n);

    for (int i = 0; i < n; i++) x[i + n] = x[i], y[i + n] = y[i];
    for (int i = 0; i < 2 * n; i++) {
        mx[i] = fix(x[i]), my[i] = fix(y[i]);
        px[i + 1] = add(px[i], mx[i]), py[i + 1] = add(py[i], my[i]);
    }
        
    ll A = 0;
    for (int i = 1; i + 1 < n; i++)
        A += area(0, i, i + 1);

    assert(A > 0);

    //cout << A << endl;

    int X = 0, D = 0, p = 0;
    ll C = 0;
    for (int i = 0; i < n; i++) {
        if (i) {
            int s = mult(p - i, sub(mult(mx[i - 1], my[i]), mult(my[i - 1], mx[i])));
            s = add(s, mult(sub(my[i - 1], my[i]), sub(px[p + 1], px[i + 1])));
            s = add(s, mult(sub(mx[i], mx[i - 1]), sub(py[p + 1], py[i + 1])));
            D = sub(D, s);
            C -= area(i - 1, i, p);
        }

        while (p + 1 < 2 * n) {
            ll k = C + area(i, p, p + 1);
            if (k <= (A - 1) / 2 || (p + 1 < n && !(A & 1) && k == A / 2)) {
                C = k;
                D = add(D, fix(C));
                p++;
            } else break;
        }

        //cout << i << ' ' << p << ' ' << C << endl;

        X = add(X, D);
    }

    cout << (((ll(n) * (n - 3) / 2) % mod * (A % mod)) % mod + 2 * (mod - X) % mod) % mod << '\n';
}