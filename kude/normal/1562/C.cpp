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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int n2 = n / 2;
    auto answer = [](int l1, int r1, int l2, int r2) {
        cout << 1 + l1 << ' ' << r1 << ' ' << 1 + l2 << ' ' << r2 << '\n';
        return;
    };
    for(int i = n2; i < n; i++) if (s[i] == '0') {
        int x = i - n2;
        answer(x, x + n2 + 1, x, x + n2);
        return;
    }
    for(int i = n - n2; i >= 0; i--) if (s[i] == '0') {
        answer(i, n, i + 1, n);
        return;
    }
    answer(0, n2, 1, n2 + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}