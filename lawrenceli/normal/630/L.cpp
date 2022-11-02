#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;

string s;

int d(int i) { return s[i] - '0'; }

int main() {
    cin >> s;
    ll a = d(1) + 10 * d(3) + 100 * d(4) + 1000 * d(2) + 10000 * d(0);
    ll b = 1;
    for (int i = 0; i < 5; i++) {
        b *= a; b %= 100000;
    }
    cout << setfill('0') << setw(5) << b << '\n';
}