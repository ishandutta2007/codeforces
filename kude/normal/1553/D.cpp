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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        string s, t;
        cin >> s >> t;
        reverse(all(s)), reverse(all(t));
        int n = t.size();
        int m = s.size();
        VI idx[26];
        rep(i, m) idx[s[i] - 'a'].push_back(i);
        rep(x, 26) reverse(all(idx[x]));
        int now = 0;
        bool ok = true;
        rep(i, n) {
            int x = t[i] - 'a';
            while(!idx[x].empty() && (idx[x].back() < now || idx[x].back() % 2 != i % 2)) idx[x].pop_back();
            if (idx[x].empty()) {
                ok = false;
                break;
            }
            now = idx[x].back() + 1; idx[x].pop_back();
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}