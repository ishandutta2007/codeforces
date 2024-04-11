#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
string s;


void solve() {
    cin >> s;
    char fst = s[0], lst = s.back();
    int dir = fst < lst ? 1 : -1;

    int n = s.size();
    vector <int> ans;
    ans.push_back(1);

    while (fst != lst) {
        for (int i = 0 ; i < n ; ++ i) if (s[i] == fst && i != 0) {
           ans.push_back(i + 1);
        }
        fst += dir;
    }
    for (int i = 0 ; i < n ; ++ i) if (i != 0 && s[i] == lst && i != n - 1) ans.push_back(i + 1);
    ans.push_back(n);
    cout << abs(s.back() - s[0]) << ' ' << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {

    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }

}