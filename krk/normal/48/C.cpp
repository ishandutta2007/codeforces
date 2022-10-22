#include <iostream>
using namespace std;

const int Maxn = 1001;

int n, a[Maxn];
double lw = 10, hg = 10000000;

int main()
{
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        lw = max(lw, (double) 10 * a[i + 1] / (i + 1));
        hg = min(hg, (double) 10 * (a[i + 1] + 1) / (i + 1));
    }
    lw = (n + 1) * lw - 10 * a[n]; hg = (n + 1) * hg - 10 * a[n];
    int st = int(lw / 10.); if (10 * st + 10 <= lw) st++;
    int en = int(hg / 10.); if (10 * en == hg) en--;
    if (st == en) {
           cout << "unique\n";
           cout << a[n] + st << endl;
    } else cout << "not unique\n";
    return 0;
}