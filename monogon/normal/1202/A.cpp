
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
string x, y;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> x >> y;
        int m = x.length();
        int n = y.length();
        int k = 0;
        while(y[n - k - 1] == '0') k++;
        int k2 = 0;
        while(m - k2 - 1 - k >= 0 && x[m - k2 - 1 - k] == '0') k2++;
        cout << k2 << endl;
    }
}