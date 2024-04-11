
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
    int n = s.length();
    vector<array<int, 26>> nxt(n + 1);
    rep(c, 0, 26) nxt[n][c] = n;
    vi mm(n + 1);
    mm[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        rep(c, 0, 26) nxt[i][c] = nxt[i + 1][c];
        nxt[i][s[i] - 'a'] = i;
        mm[i] = mm[i + 1] | (1 << (s[i] - 'a'));
    }
    int mask = 0;
    string ans;
    int idx = 0;
    while(mask != mm[0]) {
        for(int c = 25; c >= 0; c--) {
            if(mask >> c & 1) continue;
            if((mm[nxt[idx][c]] | mask) == mm[0]) {
                mask |= (1 << c);
                idx = nxt[idx][c];
                ans.push_back('a' + c);
                break;
            }
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