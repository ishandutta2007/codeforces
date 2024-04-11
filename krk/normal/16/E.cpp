#include <iostream>
#include <iomanip>
using namespace std;

const int Maxn = 18;

int n;
double a[Maxn][Maxn], prob[1 << Maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    prob[(1 << n) - 1] = 1.0;
    for (int m = (1 << n) - 1; m > 0; m--) {
        int bits = 0;
        for (int i = 0; i < n; i++) if (1 << i & m) bits++;
        int all = bits * (bits - 1) / 2;
        for (int i = 0; i < n; i++) if (1 << i & m)
            for (int j = 0; j < n; j++) if (1 << j & m && i != j)
                prob[m & ~(1 << j)] += prob[m] * 1.0 / all * a[i][j];
    }
    cout << fixed << setprecision(7);
    for (int i = 0; i < n; i++)
        cout << prob[1 << i] << (i + 1 < n? " ": "\n");
    return 0;
}