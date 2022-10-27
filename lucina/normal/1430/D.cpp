#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
char s[nax];
int n;

void solve() {
    cin >> n >> (s + 1);
    vector <int> b;

    for (int i = 1 ; i <= n ; ) {
        int j = i;
        while (j <= n && s[j] == s[i]) ++ j;
        b.push_back(j - i);
        i = j;
    }


    int m = b.size();

    int ans = m;
    vector <int> bar;

    for (int i = 0 ; i < m ; ++ i) {
        if (b[i] > 2) bar.push_back(i);
    }
    reverse(bar.begin(), bar.end());
    for (int i = 0 ; i < m ; ++ i) {
        while (!bar.empty() && bar.back() <= i) bar.pop_back();
        if (b[i] > 1) continue;
        while (!bar.empty() && b[bar.back()] == 2) bar.pop_back();
        if (!bar.empty()) {
            b[bar.back()] -= 1;
            if (b[bar.back()] == 2) bar.pop_back();
        } else {
            int ct = 0;
            for (int j = i ; j < m ; ++ j)
                if (b[j] == 1) ct += 1;
            ans -= ct / 2;
            break;
        }
    }
    cout << ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}