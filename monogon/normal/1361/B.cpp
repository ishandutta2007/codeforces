
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e6 + 5, M = 1e9 + 7;
int t, n, k[N];
ll pp[21], p;

ll powmod(ll a, ll b) {
    ll x = 1;
    while(b > 0) {
        if(b & 1) {
            x = (x * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return x;
}

// set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> p;
        rep(i, 0, n) {
            cin >> k[i];
        }
        if(p == 1) {
            cout << n % 2 << '\n';
            continue;
        }
        pp[0] = 1;
        rep(i, 1, 21) {
            pp[i] = min((ll) n, pp[i - 1] * p);
        }
        sort(k, k + n);
        ll amt = 0, dif = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(amt > 0) {
                dif -= powmod(p, k[i]);
                amt--;
            }else {
                dif += powmod(p, k[i]);
                amt = 1;
            }
            // wtf is wrong with me
            if(i > 0 && amt > 0 && amt < n) {
                int kk = k[i] - k[i - 1];
                if(kk > 20) {
                    amt = n;
                }else {
                    amt = min((ll) n, amt * pp[kk]);
                }
                // while(amt < n && kk > 0) {
                //     kk--;
                //     amt *= p;
                // }
                // amt = amt * p^(k[i] - k[i - 1]);
                // amt = (amt * powmod(p, k[i] - k[i - 1])) % M;
            }
            dif %= M;
        }
        cout << (dif + M) % M << '\n';
    }
}