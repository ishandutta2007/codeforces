#include <iostream>
const int maxn = 1e5 + 5;
using namespace std;
long long x1[maxn], y1[maxn];
unsigned long long  x2[maxn], y2[maxn];
int n;
unsigned long long x[maxn], y[maxn];
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        x1[i] = x1[i-1] + x[i];
        x2[i] = x2[i-1] + x[i]*x[i];
        y1[i] = y1[i-1] + y[i];
        y2[i] = y2[i-1] + y[i]*y[i];
    }
    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (i - 1) * (x[i] * x[i]) - 2 * x[i] * x1[i - 1] + x2[i - 1];
        ans += (i - 1) * (y[i] * y[i]) - 2 * y[i] * y1[i - 1] + y2[i - 1];
    }
    cout << ans << endl;
    return 0;
}