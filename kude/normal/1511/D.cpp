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

VI solve() {
    int n, k;
    cin >> n >> k;
    VI ans{0};
    n--; if(!n) return ans;
    while(1) {
        rep(i, k) {
            // current pos = i
            ans.push_back(i);
            n--; if(!n) return ans;
            for(int j = i + 2; j < k; j++) {
                ans.push_back(j);
                n--; if(!n) return ans;
                ans.push_back(i);
                n--; if(!n) return ans;
            }
            if (i != k - 1) {
                ans.push_back(i + 1);
                n--; if(!n) return ans;
            } else {
                rrep(j, k - 1) {
                    ans.push_back(j);
                    n--; if(!n) return ans;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    VI a = solve();
    int n = a.size();
    rep(i, n) cout << char('a' + a[i]);
    cout << endl;
}