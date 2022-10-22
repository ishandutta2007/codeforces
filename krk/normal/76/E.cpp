#include <iostream>
using namespace std;

const int Maxn = 100000;

long long n, x[Maxn], y[Maxn], X, Y, ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i]; X += x[i];
        cin >> y[i]; Y += y[i];
    }
    for (int i = 0; i < n; i++) {
        X -= x[i]; Y -= y[i];
        ans += (n - 1) * x[i] * x[i] + (n - 1) * y[i] * y[i]
               - 2 * x[i] * X - 2 * y[i] * Y;
    }
    cout << ans << endl;
    return 0;
}