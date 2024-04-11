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


bool ok(const VI& a) {
    int n = a.size();
    rep(i, n - 1) if (a[i] > a[i + 1]) return false;
    return true;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        int ans = 1001001001;
        {
            auto t = a;
            int cnt = 0;
            while(!ok(t)) {
                if (cnt % 2 == 0) sort(t.begin() + 1, t.end());
                else sort(t.begin(), t.end() - 1);
                cnt++;
            }
            chmin(ans, cnt);
        }
        {
            auto t = a;
            int cnt = 0;
            while(!ok(t)) {
                if (cnt % 2 == 1) sort(t.begin() + 1, t.end());
                else sort(t.begin(), t.end() - 1);
                cnt++;
            }
            chmin(ans, cnt);
        }
        cout << ans << '\n';
    }
}