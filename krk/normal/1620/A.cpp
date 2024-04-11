#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        int n = 0;
        for (int i = 0; i < s.length(); i++)
            n += s[i] == 'N';
        printf("%s\n", n == 1? "NO": "YES");
    }
    return 0;
}