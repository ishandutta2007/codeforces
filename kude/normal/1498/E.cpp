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

bool query(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    string ret;
    cin >> ret;
    return ret == "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    VI k(n);
    rep(i, n) cin >> k[i];
    vector<P> d;
    rep(i, n) rep(j, i) {
        if (k[i] < k[j]) d.emplace_back(i, j);
        else d.emplace_back(j, i);
    }
    sort(all(d), [&](P x, P y) {
        auto [ix, jx] = x;
        auto [iy, jy] = y;
        return k[jx] - k[ix] > k[jy] - k[iy];
    });
    for(auto [i, j]: d) {
        if (query(j, i)) {
            cout << "! " << i + 1 << ' ' << j + 1 << endl;
            return 0;
        }
    }
    cout << "! 0 0" << endl;
}