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
        string s;
        cin >> s;
        VI a;
        int now = 0;
        char cnow = s[0];
        rep(i, n) {
            if (s[i] == cnow) now++;
            else {
                a.push_back(now);
                cnow = s[i];
                now = 1;
            }
        }
        a.push_back(now);
        int sz = a.size();
        int nxtdel = 0;
        now = 0;
        int ans = 0;
        while(nxtdel < sz) {
            while(now < nxtdel) ++now;
            while(now < sz && a[now] <= 1) now++;
            if (now == sz) {
                ++ans;
                nxtdel += 1;
            } else {
                ++ans;
                --a[now];
            }
            ++nxtdel;
        }
        cout << ans << endl;
    }
}