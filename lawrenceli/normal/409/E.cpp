#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-6;

int main() {
    double x; cin >> x;
    for (int a=1; a<=10; a++)
        for (int h=1; h<=10; h++) {
            double d = a*h*1./sqrt(a*a+4*h*h);
            if (abs(d-x) < EPS) {
                cout << a << ' ' << h << '\n';
                return 0;
            }
        }

    cout << "SOMETHING'S WRONG\n";
    return 0;
}