#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using ull = unsigned long long;
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
        VL p(n);
        rep(i, n) cin >> p[i], p[i]--;
        VI seen(n);
        VL ans;
        int j = n - 1;
        rrep(i, n) {
            if (seen[i]) continue;
            int t = j;
            while(p[j] != i) j--;
            for(int k = j; k <= t; ++k) {
                ans.push_back(p[k]);
                seen[p[k]] = true;
            }
            j -= 1;
        }
        rep(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
    }
}