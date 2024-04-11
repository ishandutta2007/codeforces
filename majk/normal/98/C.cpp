#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int A, B, L; cin >> A >> B >> L;
    if (L <= min(A,B)) {
        cout << L << endl;
        return 0;
    }

    
    auto ans = [&](long double a) {
        long double b = sqrt(L*L - a*a);

        // ax    + by    + c = 0
        // a*x_2         + c = 0   => a=y_1
        //       + b*y_1 + c = 0   => b=x_2
        //                         => c=-x_2 * y_1


        return (a * A + b * B - a*b) / L;
    };

    long double l = 0, r = L, fl = ans(l), fr = ans(r); 
    for (int i = 0; i < 400; ++i) {
        long double m = (2*l+r)/3;
        long double n = (l+2*r)/3;
        long double fm = ans(m);
        long double fn = ans(n);
        if (fm < fn) {
            r = n;
            fr = fn;
        } else {
            l = m;
            fl = fm;
        }
    }

    if (fl < 1e-8) {
        cout << "My poor head =(\n";
    } else {
        fl = min((long double) L, fl);
        if (L <= max(A,B)) fl = max(fl, (long double)min(A,B));
        cout << fixed << setprecision(10) << fl << endl;
    }
}