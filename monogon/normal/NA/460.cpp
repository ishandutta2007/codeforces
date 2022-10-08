
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    if(n % k != 0) {
        cout << -1 << '\n';
        return;
    }
    array<int, 26> cnt{0};
    rep(i, 0, n) cnt[s[i] - 'a']++;
    bool flag = true;
    rep(i, 0, 26) {
        if(cnt[i] % k != 0) flag = false;
    }
    if(flag) {
        cout << s << '\n';
        return;
    }
    rep(i, 0, 26) cnt[i] %= k;
    for(int p = n - 1; p >= 0; p--) {
        cnt[s[p] - 'a'] = (cnt[s[p] - 'a'] + k - 1) % k;
        rep(ch, s[p] - 'a' + 1, 26) {
            int sum = 0;
            cnt[ch] = (cnt[ch] + 1) % k;
            rep(i, 0, 26) {
                sum += (k - cnt[i]) % k;
            }
            if(sum <= n - p - 1) {
                int idx = 0;
                s[p] = 'a' + ch;
                rep(i, p + 1, n) {
                    while(idx < 26 && cnt[idx] == 0) idx++;
                    if(idx == 26) s[i] = 'a';
                    else {
                        s[i] = 'a' + idx;
                        cnt[idx] = (cnt[idx] + 1) % k;
                    }
                }
                sort(s.begin() + p + 1, s.end());
                cout << s << '\n';
                return;
            }
            cnt[ch] = (cnt[ch] + k - 1) % k;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}