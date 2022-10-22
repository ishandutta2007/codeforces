#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double LD;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
 
ll binpow(ll n, ll p) {
    if(p == 0) return 1ll;
    ll q = binpow(n, p / 2);
    q = (q * q) % base;
    return (p % 2?q * n : q) % base;
}

const int N = 100100;

ll fact[N];

ll C(ll n, ll k) {
    if(n < k) return 0ll;
    ll A, B, C;
    A = fact[n];
    B = binpow(fact[k], base - 2);
    C = binpow(fact[n - k], base - 2);
    A = (A * B) % base;
    A = (A * C) % base;
    return A;
}

bool solve()
{
    fact[0] = 1ll;
    for(int i = 1;i < N;i++) {
        fact[i] = (fact[i - 1] * ll(i)) % base;
    }

    int n;

    cin >> n;

    ll ans = 0;

    for(int i = 1;i <= n;i++) {
        ans = (ans + (C(n, i) * binpow(20ll, i) % base) * binpow(7ll, n - i) % base) % base;
    }   

    cout << ans << '\n';

    return true;
} 

int main() {

    //while(solve());
    solve();

    return 0;
}