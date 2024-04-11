#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>

using namespace std;

int n;
string s;
vector<string> v;

int nxt(int st) {
    for (int i=st; i<n; i++)
        if (s[i] == '.') return i;

    return n;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s;
    n = s.length();

    for (int i=0; i<n; ) {
        int m = nxt(i);
        if (m - i > 8 || m == i) {
            cout << "NO\n";
            return 0;
        }

        int j;
        for (j=m+1; j<n && j<=m+3 && s[j] != '.'; j++);

        if (j<n && s[j] == '.') j--;

        if (j - m == 1) {
            cout << "NO\n";
            return 0;
        }

        v.push_back(s.substr(i, j-i));

        i = j;
    }

    cout << "YES\n";
    for (int i=0; i<v.size(); i++)
        cout << v[i] << '\n';

    return 0;
}