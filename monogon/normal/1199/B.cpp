
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll H, L;

int main() {
    cin >> H >> L;
    // D = (L^2 - H^2) / (2H)
    double D = (1.0 * L * L - H * H) / (2 * H);
    cout << fixed << setprecision(10) << D << endl;
}