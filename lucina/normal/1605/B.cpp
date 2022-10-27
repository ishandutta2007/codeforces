#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
char s[nax];
void solve() {
    cin >> n >> s + 1;
    vector <int> ans;
    while (!is_sorted(s + 1, s + 1 + n)) {
        int a = find(s + 1, s + 1 + n, '1') - s;
        int j = n;
        while (s[j] != '0') --j;
        swap(s[a], s[j]);
        ans.push_back(a);
        ans.push_back(j);
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) return cout << "0\n", void();
    cout << "1\n";
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Missing the contest. :3
*/