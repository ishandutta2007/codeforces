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

bool seen[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        rep(i, 101) seen[i] = false;
        vector<int> rest;
        vector<int> ans;
        rep(i, n) {
            int x;
            cin >> x;
            if (!seen[x]) seen[x] = true;
            else rest.push_back(x);
        }
        rep(i, 101) if (seen[i]) ans.push_back(i);
        for(int x: rest) ans.push_back(x);
        assert(ans.size() == n);
        rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
}