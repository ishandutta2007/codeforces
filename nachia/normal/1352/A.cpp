#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{

    void Solve() {
        UL t; cin >> t;
        while (t--) {
            UL n; cin >> n;
            vector<UL> ans;
            if (n >= 10000) ans.push_back(n / 10000 * 10000); n %= 10000;
            if (n >= 1000) ans.push_back(n / 1000 * 1000); n %= 1000;
            if (n >= 100) ans.push_back(n / 100 * 100); n %= 100;
            if (n >= 10) ans.push_back(n / 10 * 10); n %= 10;
            if (n) ans.push_back(n);
            cout << ans.size() << endl;
            rep(i, ans.size()) {
                if (i) cout << " "; cout << ans[i];
            } cout << endl;
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}