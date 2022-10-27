#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    map <int, int> setik;
    for (int i = 1 ; i <= n ; ++ i) cin >> a[i], setik[a[i]] += 1;
    int lst_good = n;
    for (int i = n - 1 ; i >= 1 ; -- i) {
        if (a[i] > a[i + 1]) {
            break;
        }
        lst_good = i;
    }

    int start = setik.size();

    for (int i = 1 ; i <= n ;) {
        int cur = a[i];
        if (i >= lst_good) {
            cout << start - setik.size() << '\n';
            return;
        }
        vector <int> stk;
        stk.push_back(cur);
        if (setik.count(cur)) {
            while (!stk.empty()) {
                while (setik.count(stk.back())) {
                    setik[a[i]] -= 1;
                    stk.push_back(a[i]);
                    if (setik[a[i]] == 0) setik.erase(a[i]);
                    i += 1;
                }
                stk.pop_back();
            }
        } else {
            i += 1;
        }
    }
    cout << start - setik.size() << '\n';


}
int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}