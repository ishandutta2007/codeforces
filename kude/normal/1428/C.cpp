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
    int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int n = s.size();
        int bcnt = 0, d = 0;
        rrep(i, n) {
            if (s[i] == 'B') bcnt++;
            else {
                if (bcnt > 0) {
                    bcnt--;
                    d += 2;
                }
            }
        }
        d += (bcnt / 2) * 2;
        cout << n - d << endl;
    }
}