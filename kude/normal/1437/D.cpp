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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        queue<int> q;
        q.push(0);
        int pre = 1001001001;
        int now = 0;
        for(int i = 1; i < n; i++) {
            if (a[i] < pre) {
                now = q.front() + 1; q.pop();
            }
            pre = a[i];
            q.push(now);
        }
        cout << now << '\n';
    }
}