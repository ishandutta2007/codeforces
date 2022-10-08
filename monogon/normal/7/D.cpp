
#pragma GCC optimize("Ofast")
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
    string s;
    cin >> s;
    int n = s.length();
    vi d1(n), d2(n);
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if(i + k > r) {
            r = i + k;
            l = i - k;
        }
    }
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
        while(i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k--;
        if(i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    vi deg(n, 0);
    ll ans = 0;
    rep(i, 0, n) {
        if(i % 2 == 0) {
            int c = i / 2;
            if(d1[c] == c + 1) {
                if(c == 0) deg[i] = 1;
                else deg[i] = deg[c - 1] + 1;
            }
        }else {
            int c = (i + 1) / 2;
            if(d2[c] == c) {
                deg[i] = deg[c - 1] + 1;
            }
        }
        ans += deg[i];
    }
    cout << ans << '\n';
}