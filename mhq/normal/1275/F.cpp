#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool ok = false;
        int cnt0 = 0;
        int sm = 0;
        for (char& c : s) ok |= c == '0';
        for (char& c : s) {
            if ((c - '0') % 2 == 0) cnt0++;
            sm += (c - '0');
        }
        if (ok && cnt0 > 1 && sm % 3 == 0) cout << "red\n";
        else cout << "cyan\n";
    }
    return 0;
}