#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int stuff(int x) {
    return x >= 0 ? x / 2 : x;
}

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    cout << (stuff(a - x) + stuff(b - y) + stuff(c - z) >= 0 ? "Yes\n" : "No\n");
}