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
    int n;
    cin >> n;
    VI p(n);
    rep(i, n) cin >> p[i], p[i]--;
    VVI ans(n, VI(n));
    rep(i, n) {
        // >= i
        int k = 0;
        rep(j, n - i) {
            int i1 = i + j;
            while(p[k] < i) k++;
            ans[i1][j] = p[k++] + 1;
        }
    }
    rep(i, n) rep(j, i + 1) cout << ans[i][j] << " \n"[j == i];
}