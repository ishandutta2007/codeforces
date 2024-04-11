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
        map<int, int> hist;
        rep(_, n) {
            int ai;
            cin >> ai;
            hist[ai]++;
        }
        VI d;
        for(auto [k, v]: hist) d.push_back(v);
        sort(rall(d));
        ll cnt = 0;
        for(int i = 1; i < d.size(); i++) cnt += d[i];
        ll t = cnt < d[0] ? cnt : (d[0] + cnt) / 2;
        cout << n - 2 * t << '\n';
    }
}