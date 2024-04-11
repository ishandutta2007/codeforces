#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        s[0] = s[int(s.length()) - 1];
        cout << s << endl;
    }
    return 0;
}