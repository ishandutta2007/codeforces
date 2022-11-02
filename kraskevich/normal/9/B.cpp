#include <iostream>
#include <cmath>
using namespace std;

typedef long long i64;

i64 sqr(int a)
{
    return (i64)a * a;
}

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

const double eps = 1e-7;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    double vb, vs;
    
    cin >> vb >> vs;
    
    int x[n];
    
    for(int i = 0; i < n; ++i)
            cin >> x[i];
    
    double xu, yu;
    cin >> xu >> yu;
    
    double t = 0, best = 1e18, D;
    int ansN;
    
    for(int i = 1; i < n; ++i)
    {
            t += (double)(x[i] - x[i - 1]) / vb;
            double curd = dist(x[i], 0, xu, yu);
            if(curd / vs + t < best - eps || fabs(curd / vs + t - best) < eps && curd < D)
                    best = t + curd / vs, D = curd, ansN = i;
    }
    
    cout << ansN + 1 << endl;
    
    cin >> n;
    
    return 0;
}