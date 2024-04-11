#include <iostream>
#include <cmath>
using namespace std;

const int Maxn = 105;
const double eps = 1e-7;

int n;
double vb, vs;
double x[Maxn], xu, yu;
double besttim = 1000000000.0;
int best = 1;

double Dist(double x1, double y1, double x2, double y2) 
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    cin >> n >> vb >> vs;
    for (int i = 1; i <= n; i++) cin >> x[i];
    cin >> xu >> yu;
    for (int i = 2; i <= n; i++) {
        double curtim = x[i] / vb + Dist(x[i], 0, xu, yu) / vs;
        if (curtim < besttim + eps || 
            fabs(curtim - besttim) < eps && Dist(x[i], 0, xu, yu) < Dist(x[best], 0, xu, yu)) {
                        best = i;
                        besttim = curtim;
        }
    }
    cout << best << endl;
    return 0;
}