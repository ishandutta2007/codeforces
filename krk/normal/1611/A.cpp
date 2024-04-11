#include <bits/stdc++.h>
using namespace std;

int T;
string s;

bool Even(char ch) { return (ch - '0') % 2 == 0; }

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        if (Even(s[int(s.length()) - 1])) printf("0\n");
        else if (Even(s[0])) printf("1\n");
        else {
            int pnt = 0;
            while (pnt < s.length() && !Even(s[pnt])) pnt++;
            printf("%d\n", pnt < s.length()? 2: -1);
        }
    }
    return 0;
}