#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        bool sam = true;
        for (int i = 1; i < s.length(); i++)
            if (s[i] != s[i - 1]) sam = false;
        if (sam) cout << s << endl;
        else {
            string res;
            for (int i = 0; i < s.length(); i++)
                res += "01";
            cout << res << endl;
        }
    }
    return 0;
}