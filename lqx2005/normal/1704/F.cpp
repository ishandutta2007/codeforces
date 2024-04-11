#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define db double
#define x first
#define y second
#define vi vector<int>
using namespace std;
int n;
int sg[500100], vis[500100];
int SG(int x) {
    if(x <= 1000) return sg[x];
    x -= 1000;
    x = x % 34 - 34;
    return sg[x + 1000];
}
void solve() {
    string s;
    cin >> n >> s;
    int cr = 0, cb = 0;
    FOR(i, 0, sz(s) - 1) if(s[i] == 'R') cr++; else cb++;
    if(cr > cb) {
        cout << "Alice\n";
        return;
    }
    if(cr < cb) {
        cout << "Bob\n";
        return;
    }
    int ans = 0;
    int lst = 0;
    FOR(i, 1, sz(s) - 1) {
        if(s[i] == s[i - 1]) {
            ans ^= SG(i - lst);
            lst = i;
        }
    }
    ans ^= SG(sz(s) - 1 - lst + 1);
    if(ans) cout << "Alice\n";
    else cout << "Bob\n";
    return;
}
int main() {
    FOR(i, 0, 1000) {
        if(i >= 2) {
            FOR(j, 0, i - 2) vis[sg[i - 2 - j] ^ sg[j]]++;
            while(vis[sg[i]]) sg[i]++;
            FOR(j, 0, i - 2) vis[sg[i - 2 - j] ^ sg[j]]--;
        }
    }
    // FOR(i, 10000 - 34 + 1, 10000) assert(sg[i] == sg[i - 34]);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}