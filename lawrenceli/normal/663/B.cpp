#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        s = s.substr(4);
        int k = atoi(s.c_str());

        if (s.length() == 1) {
            cout << 19 << 8 + (k < 9) << k << '\n';
        } else if (s.length() == 2) {
            if (k < 99) cout << 20 << s << '\n';
            else cout << "1999\n";
        } else if (s.length() == 3) {
            if (k < 99) cout << 3 << s << '\n';
            else cout << 2 << s << '\n';
        } else {
            int x = 3099;
            for (int j = 0, m = 10000; j < s.length() - 4; j++, m *= 10)
                x += m;

            if (k < x) cout << 1;
            cout << s << '\n';
        }
    }
}