#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

string str;

bool good(int l, int r) {
    if (l != r-l) return l > r-l;
    return str.substr(0, l) >= str.substr(l, r-l);
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> str;

    int p = str.length(), ans = 0;

    while (p > 0) {
        int q = p-1;
        while (str[q] == '0') q--;
        if (!good(q, p)) {
            ans++;
            break;
        }
        ans++;
        p = q;
    }

    cout << ans << '\n';
    return 0;
}