#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    int n, t, i;
    double p, res = 0;
    cout.precision(20);
    cin >> n >> p >> t;
    vector<double> ar(n + 1, 0);
    ar[0] = 1;
    for (; t; t--) {
        for (i = n; i >= 0; i--) {
            if (i < n)
                ar[i] *= (1 - p);
            if (i)
                ar[i] += ar[i - 1] * p;
        }
    }
    for (i = 1; i <= n; i++)
        res += ar[i] * i;
    cout << res;
    return 0;
}