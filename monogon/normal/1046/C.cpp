
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    d--;
    vector<ll> s(n), p(n);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) cin >> p[i];
    int L = 1, R = d + 1;
    while(L < R) {
        int m = (L + R) / 2;
        int c = 0;
        bool ok = true;
        rep(i, m - 1, n) {
            if(i != d) {
                c++;
                if(s[i] + p[n - c] > s[d] + p[0]) {
                    ok = false;
                }
            }
        }
        if(!ok) {
            L = m + 1;
        }else {
            R = m;
        }
    }
    cout << L << '\n';
}