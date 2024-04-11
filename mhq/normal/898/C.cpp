#include <bits/stdc++.h>
using namespace std;
int n;
vector < string > a[50];
vector < string > b;
int ind = -1;
bool pref(string x, string y) {
    if (x.size() > y.size()) return false;
    for (int i = 0; i < x.size(); i++) {
        if (x[x.size() - 1 - i] != y[y.size() - 1 - i]) return false;
    }
    return true;
}
void add(string t) {
    bool ok = false;
    for (int i = 0; i < a[ind].size(); i++) {
        if (pref(t, a[ind][i])) return ;
        if (pref(a[ind][i], t)) {
            ok = true;
            a[ind][i] = t;
        }
    }
    if (!ok) a[ind].push_back(t);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    string t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        ind = -1;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == t) ind = i;
        }
        if (ind == -1) {
            b.push_back(t);
            ind = b.size() - 1;
        }
        int q;
        cin >> q;
        for (int j = 1; j <= q; j++) {
            cin >> t;
            add(t);
        }
    }
    cout << b.size() << "\n";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " " << a[i].size() << " ";
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}