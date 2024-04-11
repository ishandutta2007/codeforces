#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
    cin >> n;
    if(n <= 3) { cout << "NO" << endl; return 0; }
    if(n & 1) cout << 1 << " " << (n - 3) / 2 << endl;
    else cout << "NO" << endl;
    return 0;
}