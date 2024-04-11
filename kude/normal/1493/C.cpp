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

string solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n % k) {
        return "-1";
    }
    int hist[26] = {};
    for(auto c: s) {
        int x = c - 'a';
        hist[x]++;
    }
    rep(i, 26) hist[i] = (k - hist[i] % k) % k;
    int now = 0;
    rep(i, 26) now += hist[i];
    if (now == 0) return s;
    rrep(i, n) {
        int x = s[i] - 'a';
        hist[x]++;
        now++;
        if (hist[x] == k) {
            hist[x] = 0;
            now -= k;
        }
        int rest = n - i - 1;
        for(int j = x + 1; j < 26; ++j) {
            int t = now;
            if (hist[j] == 0) t += k - 1;
            else t -= 1;
            if (t <= rest) {
                s[i] = 'a' + j;
                if (hist[j]) hist[j] -= 1;
                else hist[j] = k - 1;
                int k = n - 1;
                for(int l = 25; l >= 0; --l) {
                    while(hist[l]) {
                        s[k--] = 'a' + l;
                        hist[l]--;
                    }
                }
                while(i < k) s[k--] = 'a';
                return s;
            }
        }
    }
    return "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        auto s = solve();
        cout << s << '\n';
    }
}