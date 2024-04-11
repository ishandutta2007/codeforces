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
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int n = s.size();
    cout << 5 << '\n';
    cout << "R " << n - 1 << '\n';
    cout << "R " << n << '\n';
    cout << "R " << n + 1 << '\n';
    cout << "L " << n + 2 << '\n';
    cout << "L " << 2 << '\n';

    return 0;
}