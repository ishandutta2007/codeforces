
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int query(int d) {
    vector<pii> ve;
    rep(x, 1, 201) if(x % d == 0) rep(y, 1, 201) {
        ve.push_back({x, y});
    }
    if(ve.empty()) return 0;
    cout << "? " << sz(ve) << endl;
    for(auto &pa : ve) cout << pa.first << ' ' << pa.second << ' ';
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vi ans(8, -1);
    int A = query(1);
    ans[0] = A;
    int L = 1, R = 8;
    while(L < R) {
        int m = (L + R) / 2;
        ans[m] = query(1 << m);
        if(ans[m] == 0) {
            R = m;
        }else {
            L = m + 1;
        }
    }
    int h = ans[L - 1] - 1;
    int w = A / ans[L - 1] - 1;
    cout << "! " << 2 * (w + h) << endl;
}