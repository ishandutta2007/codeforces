
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5, M = 1e9 + 7;
int n, a[N];
ll pow2[N];

ll modpow(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % M;
        }
        b /= 2;
        a = (a * a) % M;
    }
    return ans;
}
ll modinv(ll a) {
    return modpow(a, M - 2);
}

ll choose(ll n, ll k) {
    if(k < 0 || n < 0 || k > n) return 0;
    k = min(k, n - k);
    ll num = 1, den = 1;
    rep(i, 1, k + 1) {
        num = (num * (n - i + 1)) % M;
        den = (den * i) % M;
    }
    return (num * modinv(den)) % M;
}

// ll brute() {
//     vi p(n);
//     rep(i, 0, n) p[i] = i + 1;
//     int cnt = 0;
//     do {
//         rep(i, 1, n - 1) {
//             if(p[i] > p[i - 1] && p[i] > p[i + 1]) goto hell;
//         }
//         rep(i, 0, n) {
//             if(a[i] != 0 && a[i] != p[i]) goto hell;
//         }
//         cnt++;
//         hell:;
//     }while(next_permutation(all(p)));
//     return cnt;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> a[i];
        if(a[i] != 0) {
            ve.emplace_back(a[i], i);
        }
    }
    pow2[0] = 1;
    rep(i, 1, N) pow2[i] = (pow2[i - 1] * 2) % M;
    int k = sz(ve);
    if(k == 0) {
        cout << pow2[n - 1] << '\n';
        return 0;
    }
    sort(all(ve));
    int le = -1, ri = n;
    ll prv = n + 1, ans = 1;
    for(int i = k - 1; i >= 0; i--) {
        if(ve[i].second <= le || ve[i].second >= ri) {
            ans = 0;
            break;
        }
        if(i > 0) {
            if(ve[i - 1].second < ve[i].second) {
                ans = (ans * choose(prv - ve[i].first - 1, ri - ve[i].second - 1)) % M;
                le += prv - ve[i].first - ri + ve[i].second;
                ri = ve[i].second;
            }else {
                ans = (ans * choose(prv - ve[i].first - 1, ve[i].second - le - 1)) % M;
                ri -= prv - ve[i].first - ve[i].second + le;
                le = ve[i].second;
            }
            prv = ve[i].first;
        }
    }
    ll ways = 0;
    {
        int ri2 = ri - (prv - ve[0].first - ve[0].second + le);
        int le2 = ve[0].second;
        ways = (ways + choose(prv - ve[0].first - 1, ve[0].second - le - 1) * pow2[max(0, ri2 - le2 - 2)]) % M;
    }
    if(ve[0].first != 1) {
        int le2 = le + (prv - ve[0].first - ri + ve[0].second);
        int ri2 = ve[0].second;
        ways = (ways + choose(prv - ve[0].first - 1, ri - ve[0].second - 1) * pow2[max(0, ri2 - le2 - 2)]) % M;
    }
    ans = (ans * ways) % M;
    cout << ans << '\n';
}