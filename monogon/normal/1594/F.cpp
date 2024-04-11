
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

int ways(int s, int n, int k) {
    if(n > s) return 0;
    vi a(s - n, 0);
    vi b(n);
    while(true) {
        fill(all(b), 1);
        rep(i, 0, s - n) b[a[i]]++;
        bool ok = true;
        rep(i, 0, n) {
            int cnt = 0;
            rep(j, i, n) {
                cnt += b[j];
                if(cnt == k) {
                    ok = false;
                }
            }
        }
        if(ok) return 2;
        int idx = 0;
        while(idx < s - n && a[idx] == n - 1) {
            a[idx] = 0;
            idx++;
        }
        if(idx == s - n) break;
        a[idx]++;
    }
    return 1;
}

int solve(ll s, ll n, ll k) {
    if(n > s) return 0;
    if(n < k) {
        return s == k ? 1 : 2;
    }
    ll amt = (n / k) * k;
    return s < n + amt ? 1 : 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int s, n, k;
    // cin >> s >> n >> k;
    // rep(l, 1, k + 1) {
    //     rep(j, 1, n + 1) {
    //         rep(i, 1, s + 1) {
    //             int w = solve(i, j, l);
    //             int w2 = ways(i, j, l);
    //             if(w == w2) cout << ". ";
    //             else cout << "X ";
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    int te;
    cin >> te;
    while(te--) {
        ll s, n, k;
        cin >> s >> n >> k;
        cout << (solve(s, n, k) == 1 ? "YES\n" : "NO\n");
    }
}