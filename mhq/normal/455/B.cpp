#include <bits/stdc++.h>
using namespace std;
int n, k;
struct node {
    int t[26];
    node() {
        for (int i = 0; i < 26; i++) t[i] = -1;
    }
};
int sz = 1;
node p[(int)1e5 + 10];
//int n;
void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (p[cur].t[s[i] - 'a'] == -1) {
            p[cur].t[s[i] - 'a'] = sz;
            sz++;
        }
        cur = p[cur].t[s[i] - 'a'];
    }
}
bool solve(int v, int num, int type) {
    //cout << v << endl;
    //cout << v << endl;
    if (v == -1) {
        if (num == type) return true;
        else return false;
    }
    bool ok1 = false;
    bool is = false;
    for (int i = 0; i < 26; i++) {
        if (p[v].t[i] != -1) is = true;
    }
    if (!is) {
        if (type == 2) ok1 = true;
        else ok1 = false;
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (p[v].t[i] != -1) ok1 |= solve(p[v].t[i], 2, type);
        }
    }
    if (num == 1) {
        return ok1;
    }
    else return !ok1;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        add(s);
    }
    bool ok1 = solve(0, 1, 1);
    bool ok2 = solve(0, 1, 2);
    //cout << ok1 << " " << ok2 << '\n';
    if (ok1 == true && ok2 == true) {
        cout << "First";
    }
    if (ok1 == false && ok2 == false) {
        cout << "Second";
    }
    if (ok1 == true && ok2 == false) {
        if (k % 2) cout << "First";
        else cout <<"Second";
    }
    if (ok1 == false && ok2 == true) {
        cout << "Second";
    }
}