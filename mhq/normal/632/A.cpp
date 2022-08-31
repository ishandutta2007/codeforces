#include <bits/stdc++.h>
using namespace std;
int n;
int hlf;
int p;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    long long cur = 0;
    cin >> n >> p;
    vector < string > q;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        q.push_back(s);
    }
    reverse(q.begin(), q.end());
    for (int i = 0; i < q.size(); i++) {
        if (q[i].size() > 4) {
            cur = 2 * cur + 1;
            hlf++;
        }
        else {
            cur = 2 * cur;
        }
    }
    cout << (cur * p) - ((p / 2) * hlf);
    return 0;
}