#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int a = 0;
        for (auto c: s) a = max(a, c - '0');
        cout << a << endl;
    }
    return 0;
}