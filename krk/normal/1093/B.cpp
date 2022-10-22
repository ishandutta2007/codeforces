#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--) {
        cin >> s;
        sort(s.begin(), s.end());
        if (s[0] == s[int(s.length()) - 1])
            printf("-1\n");
        else printf("%s\n", s.c_str());
    }
    return 0;
}