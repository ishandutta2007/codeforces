#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
int n;
int a[maxN];
string s;
vector < int > g;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    g.push_back(0);
    cin >> s;
    for (int i = 0; i <= (n - 1); i++) {
        if (s[i] == '0') {
            g.push_back(i + 1);
        }
    }
    g.push_back(n);
    for (int i = 0; i + 1 < g.size(); i++) {
        vector < int > p;
        int l = g[i] + 1;
        int r = g[i + 1];
        for (int j = l; j <= r; j++) p.push_back(a[j]);
        sort(p.begin(), p.end());
        for (int j = l; j <= r; j++) {
            if (p[j - l] != j) {
                cout << "NO";
                exit(0);
            }
        }
    }
    cout << "YES";
    return 0;
}