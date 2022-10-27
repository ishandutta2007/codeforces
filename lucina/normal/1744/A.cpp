#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
string s;
int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];
    cin >> s;

    for (int i = 0 ; i < n ; ++ i)
    for (int j = i + 1 ; j < n ; ++ j) {
        if (a[i] == a[j]) {
            if (s[i] != s[j]) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";


}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}