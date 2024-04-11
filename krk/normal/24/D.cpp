#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

const int Maxn = 1001;

int n, m, ro, co;
ld x[Maxn], a[Maxn], b[Maxn], c[Maxn], d[Maxn];

void Solve()
{
     for (int i = 2; i <= m; i++) {
         ld m = a[i] / b[i-1];
         b[i] = b[i] - m * c[i-1];
         d[i] = d[i] - m * d[i-1];
     }
     x[m] = d[m] / b[m];
     for (int i = m-1; i > 0; i--)
        x[i] = (d[i] - c[i] * x[i+1]) / b[i];
}

int main()
{
    cin >> n >> m >> ro >> co;
    if (m == 1) { cout << 2 * (n - ro) << endl; return 0; }
    for (int i = n - 1; i >= ro; i--) {
            a[1] = 0; for (int i = 2; i < m; i++) a[i] = -1./4; a[m] = -1./3;
            b[1] = b[m] = 2./3; for (int i = 2; i < m; i++) b[i] = 3./4;
            c[1] = -1./3; for (int i = 2; i < m; i++) c[i] = -1./4; c[m] = 0;
            d[1] = 1 + x[1] / 3.; for (int i = 2; i < m; i++) d[i] = 1 + x[i] / 4.; d[m] = 1 + x[m] / 3.;
            Solve();
    }
    cout << fixed << setprecision(10) << x[co] << endl;
    return 0;
}