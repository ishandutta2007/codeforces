#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
int del[200005];
vector <int> o, c;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') o.push_back(i);
        else c.push_back(i);
    }
    k /= 2;
    for (int i = k; i < o.size(); ++i) del[o[i]] = 1;
    for (int i = k; i < c.size(); ++i) del[c[c.size() - 1 - i]] = 1;
    for (int i = 0; i < n; ++i) if (!del[i]) cout << s[i];
    cout << endl;
    return 0;
}