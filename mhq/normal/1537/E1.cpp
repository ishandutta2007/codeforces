#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto z = z_function(s);
    int p = 1;
    for (int q = 2; q <= n; q++) {
        if (z[p] < q - p) {
            if (s[p + z[p]] > s[z[p] % p]) {
                continue;
            }
            else {
                assert(s[p + z[p]] < s[z[p] % p]);
                p = q;
            }
        }
        else {
            if (q % p == 0) continue;
            int start = q % p;
            if (z[start] < p - start) {
                if (s[z[start] + start] > s[z[start]]) {
                    p = q;
                }
            }
            else {
                int nstart = p - q % p;
                assert(z[nstart] < p - nstart);
                if (s[z[nstart]] > s[nstart + z[nstart]]) {
                    p = q;
                }
            }
        }
    }
    string t = s.substr(0, p);
    string pt = t;
    while (pt.size() < k) pt += t;
    cout << pt.substr(0, k) << '\n';
    return 0;
}