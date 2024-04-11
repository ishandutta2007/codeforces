#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s;
    int mn = 500;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (mn < s[i] - 'a') cout << "Ann" << '\n';
        else cout << "Mike" << '\n';
        mn = min(mn, s[i] - 'a');
    }
    return 0;
}