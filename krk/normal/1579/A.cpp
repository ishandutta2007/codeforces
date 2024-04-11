#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'A') a++;
            else if (s[i] == 'B') b++;
            else c++;
        printf("%s\n", a + c == b? "YES": "NO");
    }
    return 0;
}