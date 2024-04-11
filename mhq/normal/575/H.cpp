#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
    
using namespace std;

template<typename T> T nextInt() {
    char c;
    T x = 0, p = 1;
    do { c = getchar(); } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x * p;
}

const long long MOD = (long long)1e9 + 7;
const int maxN = 1000100;

int n, i;
long long ans, f;
long long fact[maxN];
long long inv[maxN];

long long binPow(long long a, long long n) {
    long long ret = 1;
    while (n) {
        if (n & 1) {
            ret = (a * ret) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ret;
}

long long evalC(long long n, long long k) {
    long long ret = fact[n];
    ret = (ret * inv[k]) % MOD;
    ret = (ret * inv[n - k]) % MOD;
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);

    n = nextInt<int>(); 
    n++;
    fact[0] = inv[0] = 1LL;
    for (int i = 1; i <= n; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
        inv[i] = binPow(fact[i], MOD - 2);
    }  
    ans = 0;
    for (int i = 1; i <= n; i++) {
        f = evalC(n, i);
        f = (f * f) % MOD;
        ans = (ans + f) % MOD;
    }
    cout << ans << endl;
   
    return 0;
}