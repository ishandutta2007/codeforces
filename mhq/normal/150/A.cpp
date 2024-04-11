#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll q;
vector < ll > divs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> q;
    for (int i = 1; 1LL * i * i <= q; i++) {
        if (q % i == 0) {
            divs.emplace_back(i);
            if (i != (q / i)) divs.emplace_back(q / i);
        }
    }
    sort(divs.begin(), divs.end());
    vector < bool > win(divs.size(), false);
    for (int i = 0; i < divs.size(); i++) {
        bool has = false;
        for (int j = 1; j < i; j++) {
            if (divs[i] % divs[j] == 0) {
                has = true;
                if (!win[j]) win[i] = true;
            }
        }
        if (!has) {
       //     cout << i << " gg" << endl;
            win[i] = true;
        }
    }
    if (!win[divs.size() - 1]) {
        cout << 2;
        return 0;
    }
    cout << 1 << '\n';
    for (int i = 0; i + 1 < divs.size(); i++) {
        if (divs.back() % divs[i] == 0 && !win[i]) {
            cout << divs[i];
            return 0;
        }
    }
    cout << 0;
    return 0;
}