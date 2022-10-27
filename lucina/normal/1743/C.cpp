#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cin >> n >> s;
        int a = 0, b = 0, lst = 0;
        for (int i = 0 ; i < n ; ++ i) {
            int x; cin >> x;
            int na = 0, nb = 0;
            if (s[i] == '1') {
                na = max(na, max(a, b) + x);
                nb = max(nb, b + lst);
            } else {
                na = -int(1e9);
                nb = max(a, b);
            }
            swap(a, na), swap(b, nb);
            lst = x;
        }
        cout << max(a, b) << '\n';
    }




}