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
        VI h(n);
        rep(i, n) cin >> h[i];
        sort(all(h));
        if (n == 2) {
            cout << h[0] << ' ' << h[1] << '\n';
            continue;
        }
        int mn = 1001001001;
        int i_mn = -1;
        rep(i, n - 1) if (h[i + 1] - h[i] < mn) {
            mn = h[i + 1] - h[i];
            i_mn = i;
        }
        bool first = true;
        for(int i = i_mn + 1; i < n; i++) {
            if (!first) cout << ' ';
            first = false;
            cout << h[i];
        }
        for(int i = 0; i <= i_mn; i++) {
            if (!first) cout << ' ';
            first = false;
            cout << h[i];
        }
        cout << '\n';
    }
}