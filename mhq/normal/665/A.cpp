#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a, ta, b, tb;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> a >> ta >> b >> tb;
    int cnt = 0;
    string s;
    cin >> s;
    int he = 10 * (s[0] - '0') + (s[1] - '0');
    int mi = 10 * (s[3] - '0') + (s[4] - '0');
    int C = he * 60 + mi;
    for (int t = 5 * 60; t <= 23 * 60 + 59; t++) {
        if ((t - 300) % b == 0 && t + tb > C && t < C + ta) cnt++;
    }
    cout << cnt;
    return 0;
}