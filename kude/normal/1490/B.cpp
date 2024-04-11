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
        VI c(3);
        rep(i, n) {
            int a;
            cin >> a;
            c[a%3]++;
        }
        int m = n / 3;
        rep(i, 3) c[i] -= m;
        int cnt = 0;
        rep(_, 2) rep(i, 3) {
            if (c[i] > 0) {
                cnt += c[i];
                c[(i+1)%3] += c[i];
                c[i] = 0;
            }
        }
        cout << cnt << '\n';
    }
}