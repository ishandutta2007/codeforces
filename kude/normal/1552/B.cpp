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
        int n;
        cin >> n;
        VVI r(n, VI(5));
        rep(i, n) rep(j, 5) cin >> r[i][j];
        auto cmp = [&](int p, int q) {
            int cnt = 0;
            rep(j, 5) cnt += r[p][j] > r[q][j];
            return cnt >= 3;
        };
        int cand = 0;
        for(int i = 1; i < n; i++) if (cmp(cand, i)) cand = i;
        bool ok = true;
        rep(i, n) if (i != cand && cmp(cand, i)) {
            ok = false;
            break;
        }
        cout << (ok ? cand + 1 : -1) << '\n';
    }
}