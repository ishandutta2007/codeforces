#include <bits/stdc++.h>
using namespace std;

int T;
string s;
char ch;

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> s;
        cin >> ch;
        bool ok = false;
        for (int i = 0; i < s.length(); i += 2)
            if (s[i] == ch) ok = true;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}