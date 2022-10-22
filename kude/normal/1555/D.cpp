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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    VVI c(6, VI(n + 1));
    rep(z, 6) {
        char trg = 'a' + z % 3;
        rep(i, n) {
            c[z][i + 1] = c[z][i] + (s[i] != trg);
            if (z < 3) {
                if (trg == 'c') trg = 'a';
                else trg++;
            } else {
                if (trg == 'a') trg = 'c';
                else trg--;
            }
        }
    }
    rep(_, m) {
        int l, r;
        cin >> l >> r;
        --l;
        int ans = 1001001001;
        for(auto& ci: c) chmin(ans, ci[r] - ci[l]);
        cout << ans << '\n';
    }
}