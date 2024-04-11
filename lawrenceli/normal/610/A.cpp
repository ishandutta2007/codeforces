#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    if (n % 2) cout << "0\n";
    else cout << (n - 1) / 4 << '\n';
}