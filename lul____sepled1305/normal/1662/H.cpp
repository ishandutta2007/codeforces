#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;


bool good(vi vs, int k) {
    int rem = 0;
    for (int x : vs) {
        rem = (x + rem) % k;
//        cout << rem << endl;
        if(rem > 1) return false;
    }
    return rem == 0;
}
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


//    n = m = 12;
//    cout << good({n, m - 1, n - 1, m - 2}, 12) << endl;
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        vi vs, rs;
        for (int w = 0; w <= 2; w++) {
            for (int i = 1; i * i <= n - w; i++) {
                if((n - w) % i == 0) {
                    vs.push_back(i);
                    if(i * i != n - w) vs.push_back((n - w) / i);
                }
            }
        }
        sort(all(vs));
        vs.resize(unique(all(vs)) - vs.begin());
        for (int x : vs) {

            if(good({n, m - 1, n - 1, m - 2}, x) || good({m, n - 1, m - 1, n - 2}, x)) {
                rs.push_back(x);
            }
        }
        cout << sz(rs) << " ";
        for (int x : rs) cout << x << " ";
        cout << '\n';

    }


}