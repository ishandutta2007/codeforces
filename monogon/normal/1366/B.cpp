
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

int t, m;
ll n, x, l, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x >> m;
        ll L = x, R = x;
        while(m--) {
            cin >> l >> r;
            if(max(l, L) <= min(r, R)) {
                L = min(L, l);
                R = max(R, r);
            }
        }
        cout << R - L + 1 << '\n';
    }
}