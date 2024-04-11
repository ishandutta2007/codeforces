#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int n, x;
    cin >> n >> x;
    int sum = 0;
    for (int i=0; i<n; i++) {
        int a; cin >> a; sum += a;
    }

    if (sum == 0) cout << "0\n";
    else cout << (abs(sum)-1) / x + 1 << '\n';
    return 0;
}