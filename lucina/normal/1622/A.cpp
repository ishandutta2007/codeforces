#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int l[3];

bool solve() {
    for (int i = 0 ; i < 3 ; ++ i) {
        cin >> l[i];
    }
    for (int i = 0 ; i < 3 ; ++ i) {
        for (int j = i + 1 ; j < 3 ; ++ j) {
            int res = l[0] + l[1] + l[2] - l[i] - l[j];
            if (l[i] == l[j] && res % 2 == 0) return true;
            if (res == l[i] + l[j]) return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}