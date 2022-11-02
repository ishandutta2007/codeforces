#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double sqr(double a) { 
       return a * a;
}

int main() {
    int n, k;
    cin >> n >> k;
    double x[n], y[n];
    for(int i = 0; i < n; ++i)  
            cin >> x[i] >> y[i];
    double res = 0;
    for(int i = 1; i < n; ++i) 
            res += sqrt(sqr(x[i] - x[i - 1]) + sqr(y[i] - y[i - 1])); 
     printf("%.10lf", res * k / 50.0);
     cin >> n;
     return 0;
    }