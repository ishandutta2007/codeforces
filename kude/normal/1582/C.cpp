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
        int n;
        cin >> n;
        string s;
        cin >> s;
        constexpr int INF = 1001001001;
        int ans = INF;
        for(char c = 'a'; c <= 'z'; c++) {
            int cnt = 0;
            int i = 0, j = n - 1;
            while(i < j) {
                int ni = i, nj = j;
                while(ni < n && s[ni] == c) ni++;
                if (ni > j) break;
                while(nj >= 0 && s[nj] == c) nj--;
                cnt += abs(ni - i - (j - nj));
                if (s[ni] != s[nj]) {
                    cnt = INF;
                    break;
                }
                i = ni + 1, j = nj - 1;
            }
            chmin(ans, cnt);
        }
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
}