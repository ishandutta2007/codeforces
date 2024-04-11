#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        if (s.length() == 2) printf("%c\n", s[1]);
        else {
            char mn = s[0];
            for (int i = 1; i < s.length(); i++)
                mn = min(mn, s[i]);
            printf("%c\n", mn);
        }
    }
    return 0;
}