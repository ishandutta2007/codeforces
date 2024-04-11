#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        int i = 0, j = int(s.length()) - 1;
        while (i <= j) {
            char cur = 'a' + j - i;
            if (s[i] == cur) i++;
            else if (s[j] == cur) j--;
            else break;
        }
        printf("%s\n", i > j? "YES": "NO");
    }
    return 0;
}