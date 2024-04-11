#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i-k+1, k))
                pi[i] = k;
    return *max_element(pi.begin(), pi.end());
}

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.length();
    if (s[0] == s[n - 1]) {
        cout << s << '\n';
        return;
    }
    // int ans = n;
    // string t;
    // do {
    //     int kek = prefix_function(s);
    //     if (kek < ans) {
    //         ans = kek;
    //         t = s;
    //     }
    // } while (next_permutation(s.begin(), s.end()));
    // cout << t << endl;
    // sort(s.begin(), s.end());
    
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    if (*max_element(cnt.begin(), cnt.end()) == 1) {
        cout << s << '\n';
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) {
            cout << char('a' + i);
            int ok = 1;
            for (char c : s) {
                if (ok && c - 'a' == i) {
                    ok = 0;
                    continue;
                }
                cout << c;
            }
            cout << '\n';
            return;
        }
    }
    int low = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            low = i;
            break;
        }
    }
    int m = n - cnt[low];
    if (m >= cnt[low] - 2) {
        cout << char('a' + low);
        cout << char('a' + low);
        int cur = 0;
        cnt[low] -= 2;
        for (int i = 0; i + 2 < n; i++) {
            if (i % 2 == 0 || cnt[low] == 0) {
                while (cnt[cur] == 0 || cur == low) {
                    cur++;
                }
                cout << char('a' + cur);
                cnt[cur]--;
            } else {
                cout << char('a' + low);
                cnt[low]--;
            }
        }
        cout << '\n';
        return;
    } else {
        int letters = 0;
        for (int i = 0; i < 26; i++) {
            letters += cnt[i] > 0;
        }
        if (letters == 2) {
            cout << char('a' + low);
            int cur = 0;
            cnt[low]--;
            while (cnt[cur] == 0 || cur == low) {
                cur++;
            }
            for (int i = 0; i < cnt[cur]; i++) {
                cout << char('a' + cur);
            }
            for (int i = 0; i < cnt[low]; i++) {
                cout << char('a' + low);
            }
            cout << '\n';
        } else {
            cout << char('a' + low);
            cnt[low]--;
            int nxt = -1;
            for (int i = low + 1; i < 26; i++) {
                if (cnt[i]) {
                    nxt = i;
                    cout << char('a' + i);
                    cnt[i]--;
                    break;
                }
            }
            for (int i = 0; i < cnt[low]; i++) {
                cout << char('a' + low);
            }
            cnt[low] = 0;
            for (int i = nxt + 1; i < 26; i++) {
                if (cnt[i]) {
                    cout << char('a' + i);
                    cnt[i]--;
                    break;
                }
            }
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < cnt[i]; j++) {
                    cout << char('a' + i);
                }
            }
            cout << '\n';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}