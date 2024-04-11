#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
int lst = -1;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> s;
    for (int i=0; i<s.length();) {
        int j;
        for (j = i; j<s.length() && s[j] == s[i]; j++);
        for (int k=0; k<min(j-i, 2); k++) t += s[i];
        i = j;
    }
    s = t; t = "";
    for (int i=0; i<s.length(); i++) {
        if (i > 0 && s[i] == s[i-1]) {
            if (lst != -1) { lst = -1; continue; }
            else lst = i;
        }
        if (i != lst + 1 && s[i] != s[i-1]) lst = -1;
        t += s[i];
    }
    cout << t << endl;
}