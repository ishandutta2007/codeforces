
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

// count ( before i, and ) after i
// (n 0) (m 1) + (n 1) (m 2) + ... + (n k) (m k+1)

// (n k) (m k+1)
// n! m! / (k!) (k+1)! (n-k)! (m-k-1)!
// (n-k+1) (m-k) n! m! / k (k+1) (k-1)! (k!) (n-k-1)! (m-k)!
// (n k-1) (m k) (n-k+1)(m-k)/k(k+1)

const int N = 2e5 + 5, M = 1e9 + 7;
string s;
int n;
ll fact[2 * N];

ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
ll modinv(ll a) {
    return powmod(a, M - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    fact[0] = 1;
    rep(i, 1, 2 * N) {
        fact[i] = (i * fact[i - 1]) % M;
    }
    int cl = 0, op = 0;
    rep(i, 0, n) cl += (s[i] == ')');
    ll ch = 0, ans = 0;
    rep(i, 0, n) {
        if(s[i] == '(') {
            if(op == 0) {
                ch = cl;
            }else {
                ch = (((ch * (op + cl)) % M) * modinv(op + 1)) % M;
            }
            op++;
            if(op > 0 && cl > 0) ans = (ans + ch) % M;
        }else {
            if(op + cl - 1 > 0) {
                ch = (((ch * (cl - 1)) % M) * modinv(op + cl - 1)) % M;
            }
            cl--;
        }
    }
    cout << ans << '\n';
}