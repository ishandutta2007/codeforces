#include <bits/stdc++.h>
using namespace std;

int T;
string s;

bool Check(const string &s)
{
    for (int i = 0, j; i < s.length(); i = j) {
        j = i;
        while (j < s.length() && s[i] == s[j])
            j++;
        if (j - i == 1) return false;
    }
    return true;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        printf("%s\n", Check(s)? "YES": "NO");
    }
    return 0;
}