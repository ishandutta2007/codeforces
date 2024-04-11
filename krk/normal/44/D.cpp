#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

const int Maxn = 5000;

int n, x[Maxn], y[Maxn], z[Maxn];
double res = -1;

double Dist(int i, int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + 
                (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    for (int i = 1; i < n; i++)
       for (int j = i + 1; j < n; j++)
          if (res < 0) res = Dist(0, i) + Dist(0, j) + Dist(i, j);
          else res = min(res, Dist(0, i) + Dist(0, j) + Dist(i, j));
    cout << fixed << setprecision(10) << res / 2. << endl;
    return 0;
}