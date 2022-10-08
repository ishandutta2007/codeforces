
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// binary search on number of tickets
// it can be done in the first m tickets
// if greedy works.

const int N = 2e5 + 5;
int q, n, a, b, x, y;
ll p[N];
ll k, ab;

ll gcd(ll a, ll b) {
    while(b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            p[i] /= 100;
        }
        cin >> x >> a >> y >> b >> k;
        sort(p + 1, p + n + 1, greater<ll>());
        // prefix sums
        p[0] = 0;
        for(int i = 1; i <= n; i++) {
            p[i] += p[i - 1];
        }
        ab = lcm(a, b);
        if(x < y) {
            swap(x, y);
            swap(a, b);
        }
        int numXY = 0;
        int numX = 0;
        int numY = 0;
        for(int i = 1; i <= n; i++) {
            if(i % a == 0 && i % b == 0) {
                numXY++;
            }else if(i % a == 0) {
                numX++;
            }else if(i % b == 0) {
                numY++;
            }
            ll sum = (x + y) * (p[numXY]) + x * (p[numXY + numX] - p[numXY]) + y * (p[numXY + numX + numY] - p[numXY + numX]);
            if(sum >= k) {
                cout << i << endl;
                goto endloop;
            }
        }
        cout << -1 << endl;
        endloop:;
    }
}