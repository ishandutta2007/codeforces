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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int pre = -1;
        rep(i, n) if (s[i] == '1') {
            if (pre == -1) {
                for(int j = i - 1; j >= max(0, i - m); j--) {
                    s[j] = '1';
                }
            } else {
                if (pre + m >= i - m) {
                    if ((i - pre - 1) % 2 == 0) {
                        for(int j = pre + 1; j < i; j++) s[j] = '1';
                    } else {
                        int mid = (i + pre) / 2;
                        for(int j = pre + 1; j < mid; j++) s[j] = '1';
                        for(int j = i - 1; j > mid; j--) s[j] = '1';
                    }
                } else {
                    for(int j = pre + 1; j <= pre + m; j++) s[j] = '1';
                    for(int j = i - 1; j >= i - m; j--) s[j] = '1';
                }
            }
            pre = i;
        }
        if (pre != -1) for(int j = pre + 1; j <= min(n - 1, pre + m); j++) {
            s[j] = '1';
        }
        cout << s << '\n';
    }
}