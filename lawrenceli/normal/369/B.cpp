#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, l, r, sa, sk;

int main() {
    cin >> n >> k >> l >> r >> sa >> sk;
    int x = sa - sk, y, z;
    if (x != 0) {
        y = x / (n - k), z = x % (n - k);
        for (int i=0; i<z; i++) cout << y+1 << ' ';
        for (int i=z; i<n-k; i++) cout << y << ' ';
    } else {
        for (int i=0; i<n-k; i++) cout << 0 << ' ';
    }
    y = sk / k, z = sk % k;
    for (int i=0; i<z; i++) cout << y+1 << ' ';
    for (int i=z; i<k; i++) cout << y << ' ';
    return 0;
}