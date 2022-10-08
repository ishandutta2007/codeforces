
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

int t;
ll a, k;

void upd() {
    ll b = a;
    ll mn = a % 10, mx = a % 10;
    while(b > 0) {
        mn = min(mn, b % 10);
        mx = max(mx, b % 10);
        b /= 10;
    }
    a += mn * mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> k;
        rep(i, 1, min(100LL, k)) {
            upd();
        }
        cout << a << '\n';
    }
}