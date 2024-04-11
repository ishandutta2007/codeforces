#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

double m, R;
double dist;

int main() {
    cin >> m >> R;
    for (int i=0; i<m; i++) {
        dist+=2*R*m;
        if (m>1) {
            if (i==0 || i==m-1) {
                dist+=R*sqrt(2)*(1+2*(m-2));
            } else {
                dist+=R*sqrt(2)*(2+2*(m-3));
            }
        }
        int a=i-1, b=m-i-2;
        if (a>0) dist+=R*a*(a-1);
        if (b>0) dist+=R*b*(b-1);
    }
    cout << fixed << setprecision(10) << (dist/(m*m)) << endl;
}