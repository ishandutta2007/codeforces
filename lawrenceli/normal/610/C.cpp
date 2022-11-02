#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ios>

using namespace std;

string rev(string s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = s[i] == '+' ? '*' : '+';
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<string> v;
    v.push_back("+");

    for (int i = 0; i < n; i++) {
        vector<string> w;
        for (string s : v) {
            w.push_back(s + s);
            w.push_back(s + rev(s));
        }
        v = w;
    }

    for (string s : v)
        cout << s << '\n';
}