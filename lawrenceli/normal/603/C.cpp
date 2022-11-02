#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

int nimber(int a) {
    if (a < 4) {
        if (k) return a & 1;
        else return a == 1 ? 1 : a == 2 ? 2 : 0;
    } else if (a == 4) {
        if (k) return 2;
        else return 1;
    } else {
        if (a & 1) return 0;
        if (!k) return 1;
        int x = nimber(a / 2);
        return x == 1 ? 2 : 1;
    }
}

int main() {
    cin >> n >> k;
    k &= 1;
    int num = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        num ^= nimber(a);
    }

    if (num) cout << "Kevin\n";
    else cout << "Nicky\n";
}