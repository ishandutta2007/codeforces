#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[15];
int n;
int b[nax];
vector <int> all;
int64_t ans = 1e16;
void upd_min(int64_t &a, int64_t b) {
    a = min(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 1 ; i <= 6 ; ++ i) {
        cin >> a[i];
        a[i] = -a[i];
    }
    cin >> n;

    for (int i = 1 ; i <= n; ++ i)
        cin >> b[i];

    sort(a + 1, a + 1 + 6);
    sort(b + 1, b + 1 + n);

    set <tuple <int, int, int>> setik;

    for (int i = 1 ;i <= n ; ++ i) {
        for (int j = 1 ; j <= 6 ; ++ j) {
            all.push_back(b[i] + a[j]);
        }
    }
    sort(all.begin(), all.end());

    all.erase(unique(all.begin(), all.end()), all.end());

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= 6 ; ++ j) {
            if (b[i] + a[j] >= all[0]) {
                setik.emplace(b[i] + a[j], i, j);
                break;
            }
        }
    }

    upd_min(ans, get<0>(*setik.rbegin()) - all[0]);


    for (int z = 1 ; z < int(all.size()) ; ++ z) {
        int x = all[z];

        while (get<0>(*setik.begin()) < x) {
            auto [val, i, j] = *setik.begin();
            setik.erase(setik.begin());
            bool found = false;
            for (int nj = j + 1 ; nj <= 6 ; ++ nj) {
                if (b[i] + a[nj] >= x) {
                    found = true;
                    setik.emplace(b[i] + a[nj], i, j);
                    break;
                }
            }
            if (!found) {
                cout << ans << '\n';
                return 0;
            }
        }
        upd_min(ans, get<0>(*setik.rbegin()) - x);
    }

    cout << ans << '\n';

}
/*
    Good Luck
        -Lucina
*/