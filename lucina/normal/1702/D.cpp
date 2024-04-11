#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, q;
int a[nax];
int ans[nax];


void solve() {
    int p; string s;
    cin >> s >> p;
    int sum = 0;
    int n = s.size();
    vector <pair <char, int>> v;
    for (int i = 0 ; i < n ; ++ i) {
        v.emplace_back(s[i], i);
    }
    sort(v.begin(), v.end());
    vector <int> w;
    for (auto &[x, y] : v) {
        if (sum + x - 'a' + 1 > p) break;
        w.emplace_back(y);
        sum += x - 'a' + 1;
    }
    sort(w.begin(), w.end());
    string res;
    for (int id : w) {
        res += s[id];
    }
    cout << res << '\n';



}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}