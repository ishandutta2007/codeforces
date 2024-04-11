#include <bits/stdc++.h>

using namespace std;

const int N = 200005, M = 1e9 + 7;
long long n;

long long znajdz(long long n) {
    if (n == 0) return 1;
    long long poc = 2;
    long long kon = sqrt(n) + 1;
    long long ret = -1;
    while (poc <= kon) {
        long long sr = (poc + kon) / 2;
        if (3 * sr * (sr - 1) >= n) {
            ret = sr;
            kon = sr - 1;
        } else {
            poc = sr + 1;
        }
    }
    return ret;
}

int main() {

    cin >> n;

    long long pietro = znajdz(n);
    n -= (pietro - 1) * (pietro - 2) * 3 + 1;
    long long x = 2 * (pietro - 1) - 1;
    long long y = 2;
    if (n >= pietro - 2) {
        x -= pietro - 2;
        y += 2 * (pietro - 2);
        n -= (pietro - 2);
    } else {
        cout << x - n << " " << y + 2 * n << "\n";
        return 0;
    }

    if (n >= pietro - 1) {
        x -= 2 * (pietro - 1);
        n -= (pietro - 1);
    } else {
        cout << x - 2 * n << " " << y << "\n";
        return 0;
    }

    if (n >= pietro - 1) {
        x -= (pietro - 1);
        y -= 2 * (pietro - 1);
        n -= (pietro - 1);
    } else {
        cout << x - n << " " << y - 2 * n << "\n";
        return 0;
    }

    if (n >= pietro - 1) {
        x += (pietro - 1);
        y -= 2 * (pietro - 1);
        n -= (pietro - 1);
    } else {
        cout << x + n << " " << y - 2 * n << "\n";
        return 0;
    }

    if (n >= pietro - 1) {
        x += 2 * (pietro - 1);
        n -= (pietro - 1);
    } else {
        cout << x + 2 * n << " " << y << "\n";
        return 0;
    }

    cout << x + n << " " << y + 2 * n << "\n";

    return 0;
}