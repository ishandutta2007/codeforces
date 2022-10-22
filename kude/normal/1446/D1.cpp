#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

const int nmax = 200010;
int fst[nmax * 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    int amax = 0;
    rep(i, n) chmax(amax, a[i]);
    assert(amax <= 105);
    VI hist(amax + 1);
    rep(i, n) hist[a[i]] += 1;
    int fmax = 0;
    rep(i, amax + 1) chmax(fmax, hist[i]);
    int fmaxcnt = 0;
    int mi = 0;
    rep(i, amax + 1) if (hist[i] == fmax) {
        fmaxcnt++;
        mi = i;
    }
    if (fmaxcnt >= 2) {
        cout << n << endl;
        return 0;
    }
    int ans = 0;
    rep(x, amax + 1) {
        if (x == mi) continue;
        int now = nmax; // [0, i)
        rep(i, nmax * 2) fst[i] = -1;
        fst[now] = 0;
        rep(i, n) {
            if (a[i] == mi) now++;
            else if (a[i] == x) now--;
            if (fst[now] == -1) fst[now] = i + 1;
            else {
                //if (i + 1 - fst[now] > ans) {
                //    cout << x << ' ' << mi << ' ' << now << ' ' <<  fst[now] << ' ' << i + 1 << endl;
                //}
                chmax(ans, i + 1 - fst[now]);
            }
        }
    }
    cout << ans << endl;
}