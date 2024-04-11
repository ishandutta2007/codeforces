#include <bits/stdc++.h>

using namespace std;

string s;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s;
    char c = 'z' + 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] <= c) c = s[i], cout << "Mike" << '\n';
        else cout << "Ann" << '\n';
    }
    return 0;
}