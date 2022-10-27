#include<bits/stdc++.h>
using namespace std;
int n;
int a[1 << 18];


void solve () {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    int bad = 0;
    int pos = -1;

    for (int i = n ; i > 1 ; -- i) {
        if (a[i - 1] < a[i]) {
            pos = i - 1;
            break;
        }
    }

   // cout << "pos " << pos << '\n';
    if (pos == -1) return cout << 0 << '\n', void();
    for (int j = pos ; j > 1 ; -- j) {
        if (a[j] < a[j - 1]) {
            return cout << j - 1 << '\n', void();
        }
    }
    cout << 0 << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t -- ) {
            solve();
    }

}