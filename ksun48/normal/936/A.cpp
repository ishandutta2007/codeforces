#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL k, d, t;
    cin >> k >> d >> t;
    LL r = (k+d-1)/d;
    LL cook = k;
    LL uncook = r*d-k;
    double cycle = (1.0 * cook) / (1.0 * t) + (1.0 * uncook) / (2.0 * t);
    double f = 1.0 / cycle;
    LL n = f;
    double ans = n * (1.0 * r * d);
    double numleft = 1.0 - cycle * (1.0 * n);

    double ct = min(numleft / (1.0 / t), (double)cook);
    ans += ct;
    numleft -= ct * (1.0 / t);
    double uct = numleft * (2.0 * t);
    ans += uct;
    cout << fixed << setprecision(15) << ans << endl;
}