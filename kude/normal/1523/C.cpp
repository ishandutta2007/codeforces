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
        VI a(n + 1);
        rep(i, n) cin >> a[i + 1];
        VI nxt(n + 1, 1);
        VI par(n + 1, -1);
        vector<int> st{0};
        VI ans;
        for(int i = 1; i <= n; i++) {
            while(nxt[st.back()] != a[i]) st.pop_back();
            par[i] = st.back();
            nxt[st.back()]++;
            st.push_back(i);
            ans.clear();
            for(int j = i; j != 0; j = par[j]) {
                ans.push_back(a[j]);
            }
            int sz = ans.size();
            rrep(i, sz) cout << ans[i] << ".\n"[i == 0];
        }
    }
}