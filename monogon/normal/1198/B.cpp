
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// for each person, only their last receipt matters,
// and whether there is a payout afterwards.
// keep track of their last receipt and the time
// remember the largest payout at time t or after

const int MAX_N = 2e5 + 5;
int n, q, o, p;
ll x;
ll a[MAX_N];
int T[MAX_N];
// largest payout at time t or after
ll payout[MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        T[i] = 0;
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> o;
        if(o == 1) {
            cin >> p >> x;
            // pth person has x balance
            a[p - 1] = x;
            T[p - 1] = i;
        }else {
            cin >> x;
            // payout of x
            payout[i] = x;
        }
    }
    ll m = 0;
    for(int i = q; i >= 0; i--) {
        payout[i] = m = max(m, payout[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << max(a[i], payout[T[i]]) << " ";
    }
    cout << endl;
}