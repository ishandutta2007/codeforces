#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

bool is_rbs(vector <int> x) {

    int bal = 0;

    for (int j : x) {
        bal += j;
        if (bal < 0) return false;
    }
    return bal == 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        string s;
        cin >> s;
        bool ok = false;

        for (int x : {-1, 1}) {
            for (int y : {-1, 1}) {
                for (int z : {-1, 1}) {

                    vector <int> bar;
                    for (char a : s) {
                        if (a == 'A') bar.push_back(x);
                        if (a == 'B') bar.push_back(y);
                        if (a == 'C') bar.push_back(z);
                    }
                    ok |= is_rbs(bar);
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}