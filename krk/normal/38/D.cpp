#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const double eps = 1e-3;

int n;
int x1[Maxn], y1[Maxn], x2[Maxn], y2[Maxn], V[Maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if (x1[i] > x2[i]) swap(x1[i], x2[i]);
        if (y1[i] > y2[i]) swap(y1[i], y2[i]);
        V[i] = (x2[i] - x1[i]) * (x2[i] - x1[i]) * (y2[i] - y1[i]);
    }
    int i;
    for (i = 0; i < n; i++) {
        double w = V[i], x = (x1[i] + x2[i]) / 2.0, y = (y1[i] + y2[i]) / 2.0;
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (x + eps < x1[j] || x2[j] < x - eps || y + eps < y1[j] || y2[j] < y - eps) break;
            double nx = (x1[j] + x2[j]) / 2.0, ny = (y1[j] + y2[j]) / 2.0;
            x = (w * x + V[j] * nx) / (w + V[j]), y = (w * y + V[j] * ny) / (w + V[j]);
            w += V[j];
        }
        if (j >= 0) break;
    }
    cout << i << endl;
    return 0;
}