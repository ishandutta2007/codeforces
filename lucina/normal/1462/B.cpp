#include<bits/stdc++.h>
using namespace std;

const string FOO = "2020";

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        int n;
        string s;

        cin >> n >> s;

        int longest_front = 0;

        for (int i = 0 ; i < 4 ; ++ i) {
            if (s[i] != FOO[i]) break;
            longest_front += 1;
        }

        int longest_back = 0;

        for (int i = n - 1, bar = 3 ; bar >= 0 ; -- i, -- bar) {
            if (s[i] != FOO[bar]) break;
            ++ longest_back;
        }

        if (longest_back + longest_front >= 4) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}