#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

template<int mod>
class Modular {
public:
    int value;

    Modular(int value = 0) : value(value) {}

    Modular operator + (Modular b) {
        int c = value + b.value;
        if (c >= mod)
            c -= mod;
        return Modular(c);
    }

    Modular operator - (Modular b) {
        int c = value - b.value;
        if (c < 0)
            c += mod;
        return Modular(c);
    }
    
    Modular operator * (Modular b) {
        return (1LL * value * b.value) % mod;
    }

    void operator += (Modular b) {
        value += b.value;
        if (value >= mod)
            value -= mod;
    }

    void operator += (int b) {
        value += b;
        if (value >= mod)
            value -= mod;
    }

    void operator -= (Modular b) {
        value -= b.value;
        if (value < 0)
            value += mod;
    }

    void operator -= (int b) {
        value -= b;
        if (value < 0)
            value += mod;
    }

    void operator *= (Modular b) {
        value = (1LL * value * b.value) % mod;
    }

    void operator *= (int b) {
        value = (1LL * value * b) % mod;
    }

    void operator = (int b) {
        value = b;
    }

    void operator = (Modular b) {
        value = b.value;
    }
};

const int mod = 998244353;
using Mint = Modular<mod>;

Mint bin_pow(Mint a, int b) {
    if (b == 0)
        return Mint(1);
    if (b % 2 == 1)
        return bin_pow(a, b - 1) * a;
    return bin_pow(a * a, b / 2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<Mint> ans(n, 0);
    ans[n - 1] = 10;
    for (int len = 1; len < n; len++) {
        ans[len - 1] += bin_pow(Mint(10), n - len - 1) * 180;
        Mint cnt_mid = max(0, n - 1 - len), other;
        if (len == n - 1)
            other = 1;
        else
            other = bin_pow(Mint(10), n - 2 - len);
        ans[len - 1] += other * cnt_mid * Mint(9 * 9 * 10);
    }
    for (Mint i : ans)
        cout << i.value << ' ';
    cout << '\n';
}