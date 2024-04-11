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
        VI a, b;
        rep(i, n) {
            int x;
            cin >> x;
            if (i % 2 == 0) a.push_back(x);
            else b.push_back(x);
        }
        sort(rall(a));
        sort(rall(b));
        VI c;
        while(!a.empty()) {
            c.push_back(a.back()); a.pop_back();
            swap(a, b);
        }
        bool ok = true;
        rep(i, n - 1) if (c[i] > c[i + 1]) {
            ok = false;
            break;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}