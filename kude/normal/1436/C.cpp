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

const int mod = 1000000007;

int main() {
    int n, x, pos;
    cin >> n >> x >> pos;
    int tcnt = 0, fcnt = 0;
    int left = 0;
    int right = n;
    while(left < right) {
        int middle = (left + right) / 2;
        if (middle < pos) {
            ++tcnt;
            left = middle + 1;
        } else if (middle == pos) {
            left = middle + 1;
        } else {
            ++fcnt;
            right = middle;
        }
    }
    int tcand = x-1, fcand = n - x;
    //printf("%d %d %d %d\n", tcand, tcnt, fcand, fcnt);
    if (tcand < tcnt || fcand < fcnt) {
        cout << 0 << endl;
        return 0;
    }
    int rest = n-1;
    ll ans = 1;
    rep(_, tcnt) {
        ans *= tcand--;
        ans %= mod;
        rest--;
    }
    rep(_, fcnt) {
        ans *= fcand--;
        ans %= mod;
        rest--;
    }
    for(int i = 1; i <= rest; i++) {
        ans *= i;
        ans %= mod;
    }
    cout << ans << endl;
}