#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[4];



bool solve() {
    cin >> n;
    for (int i = 0 ; i < 4 ; ++ i)
        cin >> a[i];

    for (int msk = 0 ; msk < 16 ; ++ msk) {
        int b[4];
        for (int i = 0 ; i < 4 ; ++ i)
            b[i] = a[i];
        for (int j = 0 ; j < 4 ; ++ j) {
            if (msk >> j & 1) {
                -- b[j];
                -- b[(j + 3) % 4];
            }
        }
        for (int j = 0 ; j < 4 ; ++ j)
            if (b[j] < 0 || b[j] > n - 2) goto BAR;
        return true;
        BAR:;
    }
    return false;

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}