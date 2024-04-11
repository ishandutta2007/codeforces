#include <bits/stdc++.h>
using namespace std;
vector < pair < int, int > > t;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    int prv = -1;
    int gr = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - 'a' != prv) {
            if (gr != 0) t.push_back(make_pair(gr, prv));
            gr = 1;
            prv = s[i] - 'a';
        }
        else gr++;
    }
    t.push_back(make_pair(gr, prv));
    int op = 0;
    while (1) {
        if (t.size() <= 1) break;
        int mi = (int)1e6 + 10;
        for (int i = 1; i + 1 < t.size(); i++) {
            mi = min((t[i].first + 1) / 2, mi);
        }
        mi = min(mi, t[0].first);
        mi = min(mi, t[t.size() - 1].first);
        for (int i = 0; i < t.size(); i++) {
            if (i == 0 || i == t.size() - 1) {
                t[i].first -= mi;
            }
            else {
                t[i].first -= 2 * mi;
            }
        }
        op += mi;
        vector < pair < int, int > > v;
        int prv = -1;
        int cur = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i].first <= 0) continue;
            if (prv == t[i].second) {
                cur += t[i].first;
            }
            else {
                if (prv != -1) v.push_back(make_pair(cur, prv));
                cur = t[i].first;
                prv = t[i].second;
            }
        }
        v.push_back(make_pair(cur, prv));
        swap(t, v);
    }
    cout << op;
}