#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        cout << 2 << '\n';
        cout << n << ' ' << n-1 << '\n';
        int k = n-2;
        rep(_, k) {
            cout << n << ' ' << n-2 << '\n';
            --n;
        }
    }
}