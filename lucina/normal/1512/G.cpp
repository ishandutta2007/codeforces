#include<bits/stdc++.h>
using namespace std;
const int nax = 1e7 + 5;
int f[nax];
int foo[nax];

int main() {

    for (int i = 1 ; i < nax ; ++ i) {
        for (int j = i ; j < nax ; j += i) {
            f[j] += i;
        }
    }
    memset(foo, -1, sizeof(foo));
    for (int i = 1 ; i < nax ; ++ i) {
        if (f[i] >= nax || foo[f[i]] != -1) continue;
        foo[f[i]] = i;
    }
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    for (int i = 1 ; i <= T ; ++ i) {
        int c;
        cin >> c;
        cout << foo[c] << '\n';
    }

}