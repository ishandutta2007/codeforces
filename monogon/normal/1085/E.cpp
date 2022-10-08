
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int K = 27, N = 1e6 + 5;
int t, k, n, p[K];
bool used[N];
string s, a, b;

bool solve(int i, bool r) {
    if(i == n) return true;
    if(!r) {
        // find next character, doesn't matter
        if(p[s[i] - 'a'] == -1) {
            rep(c, 0, k) {
                if(!used[c]) {
                    p[s[i] - 'a'] = c;
                    used[c] = true;
                    break;
                }
            }
        }
        return solve(i + 1, false);
    }
    // required to be >= a[i]
    // try a[i] and check separately
    // do next unused character if one exists
    if(p[s[i] - 'a'] != -1) {
        // forced
        if(p[s[i] - 'a'] < a[i] - 'a') {
            return false;
        }else if(p[s[i] - 'a'] == a[i] - 'a') {
            return solve(i + 1, true);
        }else {
            return solve(i + 1, false);
        }
    }else {
        if(!used[a[i] - 'a']) {
            p[s[i] - 'a'] = a[i] - 'a';
            used[a[i] - 'a'] = true;
            if(solve(i + 1, true)) return true;
            p[s[i] - 'a'] = -1;
            used[a[i] - 'a'] = false;
        }
        rep(c, a[i] - 'a' + 1, k) {
            if(!used[c]) {
                p[s[i] - 'a'] = c;
                used[c] = true;
                return solve(i + 1, false);
            }
        }
        return false;
    }
}

void printans() {
    int ch = 0;
    rep(i, 0, k) {
        if(p[i] == -1) {
            while(used[ch]) ch++;
            assert(ch < k);
            used[ch] = true;
            p[i] = ch;
        }
        cout << (char) ('a' + p[i]);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> k >> s >> a >> b;
        n = s.length();
        fill(p, p + k, -1);
        fill(used, used + k, false);
        if(!solve(0, true)) {
            cout << "NO\n";
            continue;
        }
        // replace characters of s
        // check that a <= s && s <= b
        rep(i, 0, n) {
            s[i] = 'a' + p[s[i] - 'a'];
        }
        if(a <= s && s <= b) {
            cout << "YES\n";
            printans();
        }else {
            cout << "NO\n";
        }
    }
}