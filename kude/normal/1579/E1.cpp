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
        VI p(n);
        rep(i, n) cin >> p[i], p[i]--;
        vector<char> seen(n);
        int i = n - 1;
        int t = 0;
        VI ans_f, ans_b;
        while(i >= 0) {
            while(seen[t]) t++;
            int j = i;
            while(p[j] != t) j--;
            ans_f.push_back(t);
            seen[t] = true;
            while(i != j) {
                ans_b.push_back(p[i]);
                seen[p[i]] = true;
                i--;
            }
            i--;
        }
        ans_f.insert(ans_f.end(), rall(ans_b));
        rep(i, n) cout << ans_f[i] + 1 << " \n"[i + 1 == n];
    }
}