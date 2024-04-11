#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int best = 0, worst = 0;
        for (int i = 0; i < 10; ++i) {
            if (s[i] == '1') {
                if (i % 2 == 0) ++best, ++worst;
                else --best, --worst;
            }
            else if (s[i] == '?') {
                if (i % 2 == 0) ++best;
                else --worst;
            }
            int rema = (10 - i - 1) / 2;
            int remb = (10 - i - 0) / 2;
            if (best > remb || -worst > rema || i == 9) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}