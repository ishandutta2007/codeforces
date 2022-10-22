#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        printf("%s\n", s.find('r') < s.find('R') && s.find('g') < s.find('G') && s.find('b') < s.find('B')? "YES": "NO");
    }
    return 0;
}