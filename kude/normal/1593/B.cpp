#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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
        string s;
        cin >> s;
        int n = s.size();
        int ans = 1001001001;
        rrep(i, n) if (s[i] == '0') {
            rrep(j, i) if (s[j] == '0' || s[j] == '5') {
                chmin(ans, n - j - 2);
                break;
            }
            break;
        }
        rrep(i, n) if (s[i] == '5') {
            rrep(j, i) if (s[j] == '2' || s[j] == '7') {
                chmin(ans, n - j - 2);
                break;
            }
            break;
        }
        cout << ans << '\n';
    }
}