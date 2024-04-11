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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    VI idx_front(m), idx_back(m);
    {
        int j = 0; // pointer for s
        rep(i, m) {
            while(s[j] != t[i]) j++;
            idx_front[i] = j++;
        }
    }
    {
        int j = n - 1; // pointer for s
        rrep(i, m) {
            while(s[j] != t[i]) j--;
            idx_back[i] = j--;
        }
    }

    int ans = -1;
    rep(i, m - 1) chmax(ans, idx_back[i + 1] - idx_front[i]);
    cout << ans << '\n';
}