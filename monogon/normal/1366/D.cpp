
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

const int N = 5e5 + 5, A = 1e7 + 5;
int n, a[N], d1[N], d2[N];
int prime[A];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(p, 2, A) {
        if(prime[p] == 0) {
            for(int d = p; d < A; d += p) {
                if(prime[d] == 0) {
                    prime[d] = p;
                }
            }
        }
    }
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        int p = prime[a[i]];
        ll x = 1;
        while(a[i] % p == 0) {
            a[i] /= p;
            x *= p;
        }
        if(a[i] != 1) {
            d1[i] = x;
            d2[i] = a[i];
        }else {
            d1[i] = d2[i] = -1;
        }
    }
    rep(i, 0, n) {
        cout << d1[i] << ' ';
    }
    cout << '\n';
    rep(i, 0, n) {
        cout << d2[i] << ' ';
    }
    cout << '\n';
}