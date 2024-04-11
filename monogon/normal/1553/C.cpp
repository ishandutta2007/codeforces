
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

void solve() {
    string s;
    cin >> s;
    int ans = 10;
    rep(mask, 0, 1 << 10) {
        bool ok = true;
        rep(i, 0, 10) {
            if(s[i] != '?' && (s[i] == '1') != (mask >> i & 1)) {
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        int a = 0, b = 0;
        int kickA = 5, kickB = 5;
        rep(i, 0, 10) {
            if(mask >> i & 1) {
                (i % 2 == 0 ? a : b)++;
            }
            (i % 2 == 0 ? kickA : kickB)--;
            if(a > b + kickB || b > a + kickA) ans = min(ans, i + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}