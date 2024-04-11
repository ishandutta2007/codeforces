#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while(tst--) {
        string s;
        cin >> s;
        bool ok = false;
        for (int mask = 0; mask < 8; mask++) {
            int bal = 0;
            bool good = true;
            for (char& c : s) {
                int p = c - 'A';
                if ((mask & (1 << p))) bal++;
                else bal--;
                if (bal < 0) good = false;
            }
            if (bal != 0) good = false;
            if (good) ok = true;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}