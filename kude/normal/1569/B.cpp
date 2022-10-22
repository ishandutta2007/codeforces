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
        string s;
        cin >> s;
        vector<string> ans(n, string(n, '='));
        rep(i, n) ans[i][i] = 'X';
        VI twos;
        rep(i, n) if (s[i] == '2') twos.push_back(i);
        if (twos.size() == 1 || twos.size() == 2) {
            cout << "NO" << '\n';
            continue;
        } else if (twos.size() >= 3) {
            int i = twos[0], j = twos[1], k = twos[2];
            ans[i][j] = ans[j][k] = ans[k][i] = '+';
            ans[j][i] = ans[k][j] = ans[i][k] = '-';
            for(int p = 3; p < twos.size(); p++) {
                int l = twos[p];
                ans[l][i] = '+';
                ans[i][l] = '-';
            }
        }
        cout << "YES\n";
        rep(i, n) cout << ans[i] << '\n';
    }
}