#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        int st = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'B' && st > 0) st--;
            else st++;
        printf("%d\n", st);
    }
    return 0;
}