#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        printf("%s\n", s.length() % 2 == 0 && s.substr(0, s.length() / 2) == s.substr(s.length() / 2)? "YES": "NO");
    }
    return 0;
}