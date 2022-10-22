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
    int n;
    cin >> n;
    int n2 = n * 2;
    VI qt(n2), x(n2);
    rep(i, n2) {
        char c;
        do {
            cin >> c;
        } while(c != '+' && c != '-');
        int t = c == '+';
        qt[i] = t;
        if (t == 0) {
            int z;
            cin >> z;
            x[i] = z;
        }
    }
    vector<int> st;
    rep(i, n2) {
        if (qt[i]) {
            st.push_back(i);
        } else {
            if (st.empty()) {
                cout << "NO\n";
                return 0;
            }
            x[st.back()] = x[i];
            st.pop_back();
        }
    }
    set<int> now;
    rep(i, n2) {
        if (qt[i]) {
            now.insert(x[i]);
        } else {
            int ret = *now.begin();
            now.erase(ret);
            if (ret != x[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    VI ans;
    ans.reserve(n);
    rep(i, n2) {
        if (qt[i]) {
            ans.push_back(x[i]);
        }
    }
    cout << "YES\n";
    rep(i, n) cout << ans[i] << " \n"[i+1==n];
}