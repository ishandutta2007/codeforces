#include <iostream>
#include <string>
using namespace std;

int main() {
    string s[6];
    s[0] = "Sheldon", s[1] = "Leonard", s[2] = "Penny", s[3] = "Rajesh", s[4] = "Howard";
    long long n;
    cin >> n;
    long long t = 1;
    while(5 * t < n) {
            n -= (5 * t);
            t *= 2;
    }
    cout << s[(n - 1) / t] << endl;
    cin >> t;
    return 0;
}