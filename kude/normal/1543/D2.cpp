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

int n, k;

void ask(int y) {
    cout << y << endl;
    int r;
    cin >> r;
    if (r == 1) throw 0;
    if (r == -1) exit(0);
    return;
}

int x[30], y[30];
void solve() {
    cin >> n >> k;
    rep(i, 30) x[i] = y[i] = 0;
    rep(i, n) {
        {
            int t = i;
            rep(i, 30) {
                y[i] = t % k;
                t /= k;
            }
        }
        {
            rep(d, 30) {
                y[d] = x[d] + (i % 2 == 0 ? y[d] : -y[d]);
                y[d] = (y[d] % k + k) % k;
            }
        }
        int t = 0;
        rrep(i, 30) t = t * k + y[i];
        ask(t);
        rep(i, 30) x[i] = (y[i] - x[i]) % k;
        // rep(i, 30) cout << x[i] << " \n"[i + 1 == 30];
        // cout << flush;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        try {
            solve();
        } catch(int e){}
    }
}