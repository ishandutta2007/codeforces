#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
string s;
int n;
int a[nax];


void solve() {
    cin >> n;
    int need = n;
    vector <int> good;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            need -= 1;
            a[i] /= 2;
        }
        a[i] = i;
        good.push_back(0);
        while (a[i] % 2 == 0) {
            good.back() += 1;
            a[i] /= 2;
        }
    }
    sort(good.rbegin(), good.rend());
    if (need <= 0) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0 ; i < good.size() ; ++ i) {
        need -= good[i];
        if (need <= 0) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout  << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}