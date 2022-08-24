#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
map < char, int > mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        mp[c]++;
    }
    for (int i = 0; i < mp['n']; i++) cout << 1 << " ";
    for (int i = 0; i < mp['z']; i++) cout << 0 << " ";
    return 0;
}