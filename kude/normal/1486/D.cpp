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

int a[200000];
int df[400001], db[400001];
constexpr int B = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i], a[i]--;
    int l = 0, r = n;
    while(r - l > 1) {
        int c = l + r >> 1;
        rep(i, 2 * n + 1) df[i] = db[i] = -1;
        int now = n;
        rep(i, n + 1) {
            // now = sum a[0, i)
            if (df[now] == -1) df[now] = i;
            db[now] = i;
            if (i < n) now += (a[i] >= c ? 1 : -1);
        }
        bool ok = false;
        int mn = 1001001001;
        rep(i, 2 * n + 1) {
            if (db[i] != -1 && db[i] - mn >= k) {
                ok = true;
                break;
            }
            if (df[i] != -1) chmin(mn, df[i]);
        }
        if (ok) l = c;
        else r = c;
    }
    cout << l + 1 << '\n';
}