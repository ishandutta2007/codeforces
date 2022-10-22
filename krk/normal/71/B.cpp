#include <iostream>
using namespace std;

const int Maxn = 100;

int n, k, t;
int bar[Maxn];

int main()
{
    cin >> n >> k >> t;
    int pnt = 0;
    for (; pnt < n && (pnt+1) * 100 <= n * t; pnt++) bar[pnt] = k;
    if (pnt < n) {
            bar[pnt] = (n * k * t - 100 * pnt * k) / 100;
            if (bar[pnt] < 0) bar[pnt] = 0;
            else if (bar[pnt] > k) bar[pnt] = k;
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << bar[i];
    }
    cout << endl;
    return 0;
}