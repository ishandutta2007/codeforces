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
        string s;
        cin >> s;
        int n = s.size();
        int mn = n;
        rep(b, 2) {
            string t = s;
            rep(i, n) if (t[i] == '?') t[i] = '0' + ((i % 2) ^ b);
            int score = 0;
            int fi = 5, se = 5;
            rep(i, 10) {
                if ((score + fi) * (score - se) > 0) {
                    chmin(mn, i);
                    break;
                }
                if (i % 2 == 0) {
                    fi--;
                    score += t[i] - '0';
                } else {
                    se--;
                    score -= t[i] - '0';
                }
            }
        }
        cout << mn << '\n';
    }
}