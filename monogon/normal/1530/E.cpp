
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
    vi cnt(26, 0);
    rep(i, 0, n) cnt[s[i] - 'a']++;
    vi ve;
    rep(i, 0, 26) {
        if(cnt[i] > 0) {
            ve.push_back(i);
        }
    }
    if(sz(ve) == 1) {
        cout << s << '\n'; return;
    }
    string ans;
    int idx = -1;
    rep(i, 0, sz(ve)) {
        if(cnt[ve[i]] == 1) {
            idx = i;
            break;
        }
    }
    if(idx != -1) {
        ans.push_back(ve[idx] + 'a');
        cnt[ve[idx]]--;
        rep(i, 0, sz(ve)) {
            rep(j, 0, cnt[ve[i]]) {
                ans.push_back(ve[i] + 'a');
            }
        }
        cout << ans << '\n';
        return;
    }
    if(n >= 2 * cnt[ve[0]] - 2) {
        ans.push_back(ve[0] + 'a'); cnt[ve[0]]--;
        string s1(cnt[ve[0]], (char) (ve[0] + 'a'));
        string s2;
        rep(i, 1, sz(ve)) {
            rep(j, 0, cnt[ve[i]]) {
                s2.push_back(ve[i] + 'a');
            }
        }
        int idx = 0, jdx = 0;
        rep(i, 1, n) {
            if(i % 2 == 1 && idx < (int) s1.length()) {
                ans.push_back(s1[idx]);
                idx++;
            }else {
                ans.push_back(s2[jdx]);
                jdx++;
            }
        }
        cout << ans << '\n';
        return;
    }
    if(sz(ve) == 2) {
        ans.push_back(ve[0] + 'a');
        rep(i, 0, cnt[ve[1]]) ans.push_back(ve[1] + 'a');
        rep(i, 1, cnt[ve[0]]) ans.push_back(ve[0] + 'a');
        cout << ans << '\n';
        return;
    }
    ans.push_back(ve[0] + 'a');
    cnt[ve[0]]--;
    ans.push_back(ve[1] + 'a');
    cnt[ve[1]]--;
    while(cnt[ve[0]] > 0) {
        ans.push_back(ve[0] + 'a');
        cnt[ve[0]]--;
    }
    ans.push_back(ve[2] + 'a');
    cnt[ve[2]]--;
    rep(i, 0, sz(ve)) {
        rep(j, 0, cnt[ve[i]]) {
            ans.push_back(ve[i] + 'a');
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