#pragma warning (disable: 4996)
#include <iostream> 
#include <stdio.h> 
#include <cstdio> 
#include <algorithm> 
#include <vector> 
#include <map> 
#include <set> 
#include <string> 
#include <cstring> 
#include <valarray> 
#include <tuple> 
#include <complex> 
#include <bitset> 
#include <assert.h> 
#include <unordered_map>
#include <queue>

#define pb push_back 
#define mp make_pair 

typedef long long ll;

using namespace std;

ll n;

ll gcd(ll a, ll b) {
    ll c;
    while (b > 0) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

void solve() {
    ll i, j, x, y, p, q, xx, yy, d, t;
    for (i = 0; i < n; i++) {
        cin >> x >> y >> p >> q;
        if (p == q) {
            if (x != y) {
                cout << -1;
            } else {
                cout << 0;
            }
        } else {
            if (p == 0) {
                if (x != 0) {
                    cout << -1;
                } else {
                    cout << 0;
                }
            } else {
                t = max((y + q - 1) / q, max((x + p - 1) / p, (y - x + q - p - 1) / (q - p)));
                cout << (q*t - y);
            }
        }
        cout << endl;
    }
    return;
}

int main() {
#ifdef _DEBUG 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
    cin >> n;
    solve();
    return 0;
}