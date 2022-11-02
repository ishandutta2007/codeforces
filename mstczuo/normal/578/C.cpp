# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>

using namespace std;

int a[200000];
int n;

double calc(double x) {
    double mx = 0, mi = 0, S = 0;
    for(int i = 0; i < n; ++i) {
        S += a[i] - x;
        if(S > mx) mx = S;
        if(S < mi) mi = S;
    }
    return mx - mi;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    double L = -10000.0, R = 10000.0;
    while(R - L > 1e-12) {
        double Ml = (L + L + R) / 3, Mr = (L + R + R) / 3;
        double cl = calc(Ml), cr = calc(Mr);
        cl < cr ? R = Mr : L = Ml;
    }
    printf("%.10f\n", calc(L));
}