#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

int main() {
    cin >> n;
    long double sum1 = 0, sum2 = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            if (i < n / 2) {
                sum1 += (long double)(s[i] - '0');
            } else {
                sum2 += (long double)(s[i] - '0');
            }
        } else {
            if (i < n / 2) {
                sum1 += (long double)4.5;
            } else {
                sum2 += (long double)4.5;   
            }
        }
    }
    if (fabsl(sum1 - sum2) < 1e-9) {
        cout << "Bicarp" << endl;
    } else {
        cout << "Monocarp" << endl;
    }
}