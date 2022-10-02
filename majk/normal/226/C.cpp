#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int M;
vector<ll> times(const vector<ll> &a, const vector<ll> &b) {
    vector<ll> C(4, 0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                (C[2*i+j] += a[2*i+k] * b[2*k+j]) %= M;
            }
        }
    }
    return C;
}

int main() {
    ll L, R, K;
    cin >> M >> L >> R >> K;
    if (M == 1) { cout << 0 << endl; return 0; }

    ll ans = 1;
    for(int j = 2; j <= 100000; ++j) {
        ll l = 1 + (L-1)/j;
        ll r = R/j;
        if (r - l >= K - 1) ans = j;
    }

    for (int r = 1; r <= 100000; ++r) {
        ll j = R/r;
        if (j != 0) {
            ll l = 1 + (L-1)/j;
            if (r - l >= K - 1) ans = max(ans, j);
        }
    }
    
    vector<ll> S{1,0,0,1};
    vector<ll> U{1,1,1,0};
    while (ans) {
        if (ans&1) S = times(S, U);
        U = times(U, U);
        ans /= 2;
    }

    cout << S[1] << endl;

}