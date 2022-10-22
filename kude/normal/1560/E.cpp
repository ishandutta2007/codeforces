#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int k = 0;
    int tot_cnt[26] = {};
    for(char c: s) tot_cnt[c - 'a']++;
    rep(i, 26) k += tot_cnt[i] > 0;
    bool seen[26] = {};
    int hist[26] = {};
    string res1, res2;
    for(int i = n - 1; i >= 0;) {
        if (k == 0) {
            cout << -1 << '\n';
            return;
        }
        int nc = -1;
        for(int j = i; j >= 0; j--) {
            if (!seen[s[j] - 'a']) {
                res2 += s[j];
                nc = s[j] - 'a';
                break;
            }
        }
        if (nc == -1 || tot_cnt[nc] % k != 0) {
            cout << -1 << '\n';
            return;
        }
        hist[nc] = tot_cnt[nc] / k;
        seen[nc] = true;
        k--;
        int rest[26];
        rep(i, 26) rest[i] = hist[i];
        int j = i;
        int rcnt = 0;
        rep(i, 26) rcnt += seen[i];
        for(; j >= 0; j--) {
            int c = s[j] - 'a';
            if (!rest[c]) {
                cout << -1 << '\n';
                return;
            }
            rest[c]--;
            if (!rest[c]) {
                rcnt--;
                if (rcnt == 0) break;
            }
        }
        if (j < 0) {
            cout << -1 << '\n';
            return;
        }
        if (j == 0) {
            res1 = s.substr(0, i + 1);
            break;
        }
        i = j - 1;
    }
    reverse(all(res2));
    string tmp, t = res1;
    for(char c: res2) {
        tmp += t;
        string nt;
        for(char ti: t) if (ti != c) nt += ti;
        swap(t, nt);
    }
    if (tmp == s) {
        cout << res1 << ' ' << res2 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}