
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// (deg(n), deg(n - 1)) -> (deg(n - 1), deg(n - 2))
// (x^7, x^6 + x^4 - 1)
// (x^6 + x^4 - 1, x^5 - x) -> (x^5 - x, x^4 + x^2 - 1) ->
// (x^4 + x^2 - 1, x^3) -> (x^3, x^2 - 1) -> (x^2 - 1, x) -> (x, 1) -> (1, 0)
// x^3, x^2 - 1 => x^2 + 1, x => 1

const int N = 155;
typedef array<int, N> poly;

poly operator+(poly a, poly b) {
    poly c = {0};
    for(int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }
    return c;
}
poly operator*(poly a, poly b) {
    poly c = {0};
    for(int i = 0; i < N; i++) {
        if(a[i] != 0) {
            for(int j = 0; j < N - i; j++) {
                c[i + j] += a[i] * b[j];
            }
        }
    }
    return c;
}
void print(poly a) {
    int deg = 0;
    for(int i = 0; i < N; i++) if(a[i] != 0) deg = i;
    cout << deg << '\n';
    for(int i = 0; i <= deg; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
poly operator-(poly a) {
    poly c = {0};
    for(int i = 0; i < N; i++) {
        c[i] = -a[i];
    }
    return c;
}
int mx(poly a) {
    int m = 0;
    for(int i = 0; i < N; i++) {
        m = max(m, abs(a[i]));
    }
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    poly a = {0}, b = {0}, x = {0};
    a[0] = 1;
    x[1] = 1;
    for(int i = 0; i < n; i++) {
        poly tmp = a;
        a = x * tmp + b;
        if(mx(a) > 1) {
            a = x * tmp + (-b);
        }
        b = tmp;
    }
    print(a);
    print(b);
}