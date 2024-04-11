
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

// process queries in reverse order
// for each suffix of queries, keep track of what each digit maps to.
// we should keep track of the number it maps to, and the length of the string.
// length can be very large, what should we mod it by?
// phi(M) = 1e9 + 6

const int N = 1e5 + 5, M = 1e9 + 7;
string s, t[N];
int n, len[10];
ll ma[10];

ll powmod(ll a, ll b) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> n;
    t[0] = "0->" + s;
    rep(i, 1, n + 1) {
        cin >> t[i];
    }
    rep(i, 0, 10) {
        ma[i] = i;
        len[i] = 1;
    }
    for(int i = n; i >= 0; i--) {
        ll x = 0;
        int L = 0;
        for(int j = (int) t[i].length() - 1; j >= 3; j--) {
            x = (x + ma[t[i][j] - '0'] * powmod(10, L)) % M;
            L = (L + len[t[i][j] - '0']) % (M - 1);
        }
        len[t[i][0] - '0'] = L;
        ma[t[i][0] - '0'] = x;
    }
    cout << ma[0] << '\n';
}