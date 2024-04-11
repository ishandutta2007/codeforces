#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

bool solve() {
    cin >> n;
    for (int i = 1 ; i <= n;  ++ i)
        cin >> a[i];
    int mi = *min_element(a + 1, a + 1 + n);

    if (is_sorted(a + 1, a + 1 + n)) return true;
    vector <int> ind;
    vector <int> val;
    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] % mi == 0) {
            ind.push_back(i);
            val.push_back(a[i]);
        }
    }

    auto cop = val;
    for (int &i : val) {
        i /= mi;
    }
    if (ind.empty()) return false;
    int g = val[0];

    for (int &i : val) {
        g = __gcd(g, i);
    }
    if (g > 1) return false;
    for (int &i : val) i *= mi;
    sort(val.begin(), val.end());
    for (int i = 0 ; i < int(ind.size()) ; ++ i)
        a[ind[i]] = val[i];
    return is_sorted(a + 1, a + 1 + n);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;

    while (T --) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}