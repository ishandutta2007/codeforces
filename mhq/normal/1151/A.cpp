#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 55;
int n;
string s;
int dist(char x, char y) {
    int p = x - 'A';
    int q = y - 'A';
    return min(abs(p - q), 26 - abs(p - q));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s;
    string gen = "ACTG";
    int best = 11484848;
    for (int i = 0; i + 3 < n; i++) {
        int cur = 0;
        for (int j = 0; j < 4; j++) {
            cur += dist(s[i + j], gen[j]);
        }
        best = min(best, cur);
    }
    cout << best;
    return 0;
}