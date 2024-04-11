#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int solve() {
    int x;
    cin >> x;
    int ans = 0;
    for(int i = 1; i < 10; i++) {
        int k = 1;
        for(int y = i; y < 10000; y = y * 10 + i) {
            ans += k++;
            if (y == x) return ans;
        }
    }
    return 0;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        cout << solve() << '\n';
    }
}