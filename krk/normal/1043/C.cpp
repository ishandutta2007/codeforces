#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        int rev;
        if (i + 1 < s.length()) rev = s[i] != s[i + 1];
        else rev = s[i] == 'a';
        if (rev) reverse(s.begin(), s.begin() + i + 1);
        printf("%d%c", rev, i + 1 < s.length()? ' ': '\n');
    }
    return 0;
}