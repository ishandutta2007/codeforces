#include <iostream>
#include <algorithm>
using namespace std;

double x[200 * 1000];
int n;
double x1, x2, x3;
const double eps = 1e-7;

bool can(double d, bool fin) {
     double cur1 = x[0] + d;
     double cur2 = x[n - 1] - d;
     int i = 0;
     while(i < n && x[i] <= cur1 + d + eps)
             ++i;
     int j = n - 1;
     while(j >= 0 && x[j] >= cur2 - d - eps)
             --j;
     if(!fin) {
         if(i > j)
              return true;
         if(x[j] - x[i] > 2 * d)
                 return false;
     }
     x1 = cur1, x3 = cur2, x2 = (x[j] + x[i]) / 2.0;
     return true;
}
     

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
            cin >> x[i];
    sort(x, x + n);
    double l = 0, r = 2e9;
    for(int i = 0; i < 200; ++i) {
            double m = (l + r) / 2;
            if(can(m, false))
                      r = m;
            else
                l = m + eps;
    }
    can(l, true);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << l << endl << x1 << " " << x2 << " " << x3;
    cin >> n;
    return 0;
}