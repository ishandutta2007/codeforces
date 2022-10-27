#include<bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    cin >> T;
    while (T -- ) {
        int x;
        cin >> x;

        set <int> used;

        bool ok = true;

        while (x > 0) {
            bool once = false;
            for (int j = 9 ; j > 0 ; -- j) {
                if (used.count(j)) continue;
                if (x >= j) {
                    used.insert(j);
                    once = true;
                    x -= j;
                    break;
                }
            }
            if (!once) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "-1\n";
        } else {
            for (int i : used)
                cout << i;
            cout << '\n';
        }
    }
}